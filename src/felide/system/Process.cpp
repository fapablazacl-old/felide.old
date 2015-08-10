/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "Process.hpp"

#include <thread>
#include <boost/algorithm/string/join.hpp>
#include <Windows.h>

namespace felide { namespace system {
	static bool isWinNT() {
		OSVERSIONINFO osv = {0};
		osv.dwOSVersionInfoSize = sizeof(osv);
		GetVersionEx(&osv);
		return (osv.dwPlatformId == VER_PLATFORM_WIN32_NT);
	}

	class ProcessRedirector {
	public:
		explicit ProcessRedirector(STARTUPINFO *si, PROCESS_INFORMATION *pi, Stream *stream) {
			SECURITY_ATTRIBUTES sa = {0};
			SECURITY_DESCRIPTOR sd = {0};

			// initialize SECURITY_ATTRIBUTES
			if (isWinNT()) {
				InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
				SetSecurityDescriptorDacl(&sd, true, NULL, false);
				sa.lpSecurityDescriptor = &sd;
			} else {
				sa.lpSecurityDescriptor = NULL;
			}

			// enable process output redirection
			sa.nLength = sizeof(SECURITY_ATTRIBUTES);
			sa.lpSecurityDescriptor = &sd;
			sa.bInheritHandle = TRUE;
			
			HANDLE hStdIn = 0, hStdOut = 0;
			HANDLE hReadStdOut = 0, hWriteStdIn = 0;

			BOOL result;
			result = ::CreatePipe(&hStdIn, &hWriteStdIn, &sa, 0);
			result = ::CreatePipe(&hReadStdOut, &hStdOut, &sa, 0);
			
			si->dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
			si->wShowWindow = SW_HIDE;
			si->hStdOutput = hStdOut;
			si->hStdError = hStdOut;
			si->hStdInput = hStdIn;

			this->hStdIn = hStdIn;
			this->hStdOut = hStdOut;
			this->hReadStdOut = hReadStdOut;
			this->hWriteStdIn = hWriteStdIn;

			this->pi = pi;
			this->stream = stream;
		}

		~ProcessRedirector() {
			::CloseHandle(hStdIn);
			::CloseHandle(hStdOut);
			::CloseHandle(hReadStdOut);
			::CloseHandle(hWriteStdIn);
		}

		void handle() {
			PROCESS_INFORMATION pi = *this->pi;
			
			while (true) {
				::Sleep(10);

				// check if process is running
				unsigned long exitCode = 0;
				::GetExitCodeProcess(pi.hProcess, &exitCode);

				if (exitCode != STILL_ACTIVE) {
					return;
				}

				// check for pending reads from stdout
				const int BUFFER_SIZE = 1024;
				char buff[BUFFER_SIZE] = {0};
				DWORD readed = 0;
				DWORD avail = 0;

				::PeekNamedPipe(this->hReadStdOut, buff, BUFFER_SIZE-1, &readed, &avail, NULL);

				if (readed > 0) {
					::ZeroMemory(buff, sizeof(buff));

					if (avail > BUFFER_SIZE-1) {
						while (readed >= BUFFER_SIZE-1) {
							::ReadFile(this->hReadStdOut, buff, BUFFER_SIZE-1, &readed, NULL);
							this->stream->write(buff);
							::ZeroMemory(buff, sizeof(buff));
						}
					} else {
						::ReadFile(this->hReadStdOut, buff, BUFFER_SIZE-1, &readed, NULL);
						this->stream->write(buff);
					}
				}
			}
		}

	private:
		HANDLE hStdIn = 0, hStdOut = 0;
		HANDLE hReadStdOut = 0, hWriteStdIn = 0;
		PROCESS_INFORMATION *pi = nullptr;
		Stream *stream = nullptr;
	};

	typedef std::unique_ptr<ProcessRedirector> ProcessRedirectorPtr;

	class ProcessWin32 : public Process {
	public:
		ProcessWin32(const std::string &name) {
			std::list<std::string> args;
			this->construct(name, args, nullptr);
		}

		ProcessWin32(const std::string &name, const std::list<std::string> &args) {
			this->construct(name, args, nullptr);
		}

		ProcessWin32(const std::string &name, const std::list<std::string> &args, Stream *stream) {
			this->construct(name, args, stream);
		}

		void construct(const std::string &name, const std::list<std::string> &args, Stream *stream) {
			std::string cmdLine = name + " " + boost::join(args, " ");
			char* lpCmdLine = const_cast<char*>(cmdLine.c_str());

			STARTUPINFO si = {0};
			si.cb = sizeof(STARTUPINFO);
			
			PROCESS_INFORMATION pi = {0};

			ProcessRedirectorPtr redirector;

			if (stream) {
				redirector = std::make_unique<ProcessRedirector>(&si, &this->processInfo, stream);
			}

			// invoke process
			BOOL result = ::CreateProcess (
				nullptr, lpCmdLine,
				NULL, NULL, TRUE,
				CREATE_SUSPENDED, NULL, NULL,
				&si, &pi
			);

			if (result == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			}

			this->processInfo = pi;
			this->redirector = std::move(redirector);
		}

		virtual ~ProcessWin32() {
			::CloseHandle(this->processInfo.hProcess);
			::CloseHandle(this->processInfo.hThread);

			PROCESS_INFORMATION pi = { 0 };
			this->processInfo = pi;
		}
		
		virtual int getExitCode() const override {
			DWORD exitCode = 0;

			if (!::GetExitCodeProcess(this->processInfo.hProcess, &exitCode)) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			} else {
				return static_cast<int>(exitCode);
			}
		}

		virtual void wait() override {
			if (::WaitForSingleObject(this->processInfo.hProcess, INFINITE) == WAIT_FAILED) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			}

			this->thread.join();
		}

		virtual void start() override {
			if (::ResumeThread(this->processInfo.hThread) == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			} 

			if (this->redirector) {
				this->thread = std::thread(&ProcessRedirector::handle, this->redirector.get());
			}
		}

		virtual void terminate() override {
			if (::TerminateProcess(this->processInfo.hProcess, -1) == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			}
		}

	private:
		PROCESS_INFORMATION processInfo;
		ProcessRedirectorPtr redirector;
		std::thread thread;
	};

	typedef ProcessWin32 ProcessImpl;

	ProcessPtr Process::open(const std::string &processName) {
		return std::make_unique<ProcessImpl>(processName);
	}

	ProcessPtr Process::open(const std::string &processName, const std::list<std::string> &args) {
		return std::make_unique<ProcessImpl>(processName, args);
	}

	ProcessPtr Process::open(const std::string &processName, const std::list<std::string> &args, Stream *stream) {
		return std::make_unique<ProcessImpl>(processName, args, stream);
	}
}}
