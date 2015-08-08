/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "Process.hpp"

#include <boost/algorithm/string/join.hpp>
#include <Windows.h>

namespace felide { namespace system {

	class ProcessWin32 : public Process {
	public:
		ProcessWin32(const std::string &name) {
			std::list<std::string> args;
			this->construct(name, args);
		}

		ProcessWin32(const std::string &name, const std::list<std::string> &args) {
			this->construct(name, args);
		}

		void construct(const std::string &name, const std::list<std::string> &args) {
			std::string cmdLine = boost::join(args, " ");

			const char *lpAppName = nullptr;
			char* lpCmdLine = nullptr;

			STARTUPINFO si = { 0 };
			si.cb = sizeof(STARTUPINFO);

			// prepare application name
			lpAppName = name.c_str();

			// prepare command line
			if (cmdLine != "") {
				lpCmdLine = const_cast<char*>(cmdLine.c_str());
			}

			// prepare creation flags
			DWORD dwCreateFlags = CREATE_SUSPENDED;

			// invoke process
			PROCESS_INFORMATION pi = { 0 };
			BOOL result = ::CreateProcess (
				lpAppName, lpCmdLine,
				NULL, NULL, FALSE,
				dwCreateFlags, NULL, NULL,
				&si, &pi
			);

			if (result == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			}

			this->processInfo = pi;
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
		}

		virtual void start() override {
			if (::ResumeThread(this->processInfo.hThread) == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			} 
		}

		virtual void terminate() override {
			if (::TerminateProcess(this->processInfo.hProcess, -1) == FALSE) {
				throw std::runtime_error(std::to_string(::GetLastError()));
			}
		}

	private:
		PROCESS_INFORMATION processInfo;
	};

	typedef ProcessWin32 ProcessImpl;


	ProcessPtr Process::open(const std::string &processName) {
		return std::make_unique<ProcessImpl>(processName);
	}

	ProcessPtr Process::open(const std::string &processName, const std::list<std::string> &args) {
		return std::make_unique<ProcessImpl>(processName, args);
	}
}}
