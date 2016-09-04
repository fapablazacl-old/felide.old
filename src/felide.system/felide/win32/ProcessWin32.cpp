
#include "ProcessWin32.hpp"

#include <boost/algorithm/string/join.hpp>

namespace felide {

    ProcessWin32::ProcessWin32(ProcessFlags flags, const std::string &name) {
        std::list<std::string> args;
        this->construct(flags, name, args);
    }

    ProcessWin32::ProcessWin32(ProcessFlags flags, const std::string &name, const std::list<std::string> &args) {
        this->construct(flags, name, args);
    }

    void ProcessWin32::construct(ProcessFlags flags, const std::string &name, const std::list<std::string> &args) {
        std::string cmdLine = name + " " + boost::join(args, " ");
        char* lpCmdLine = const_cast<char*>(cmdLine.c_str());

        STARTUPINFO si = {0};
        si.cb = sizeof(STARTUPINFO);

        PROCESS_INFORMATION pi = {0};

        std::unique_ptr<ProcessRedirector> redirector;

        if (flags&ProcessFlags::Redirect) {
            redirector = std::make_unique<ProcessRedirector>(&si, &m_processInfo);
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

        m_processInfo = pi;
        m_redirector = std::move(redirector);
    }

    ProcessWin32::~ProcessWin32() {
        ::CloseHandle(m_processInfo.hProcess);
        ::CloseHandle(m_processInfo.hThread);

        PROCESS_INFORMATION pi = { 0 };
        m_processInfo = pi;
    }

    int ProcessWin32::getExitCode() const {
        DWORD exitCode = 0;

        if (!::GetExitCodeProcess(m_processInfo.hProcess, &exitCode)) {
            throw std::runtime_error(std::to_string(::GetLastError()));
        } else {
            return static_cast<int>(exitCode);
        }
    }

    void ProcessWin32::wait() {
        if (::WaitForSingleObject(m_processInfo.hProcess, INFINITE) == WAIT_FAILED) {
            throw std::runtime_error(std::to_string(::GetLastError()));
        }
    }

    void ProcessWin32::start() {
        if (::ResumeThread(m_processInfo.hThread) == FALSE) {
            throw std::runtime_error(std::to_string(::GetLastError()));
        }
    }

    void ProcessWin32::terminate() {
        if (::TerminateProcess(m_processInfo.hProcess, -1) == FALSE) {
            throw std::runtime_error(std::to_string(::GetLastError()));
        }
    }

    std::string ProcessWin32::getOutput() const {
        if (!m_redirector) {
            throw std::runtime_error("Process::getOutput: The process wasn't created with a valid redirector.");
        }

        return m_redirector->getOutput();
    }

    ProcessStatus ProcessWin32::getStatus() const {
        // TODO: Add implementation
        return ProcessStatus::Executing;
    }

    void ProcessWin32::pause() {
        // TODO: Add implementation
    }
}
