
#ifndef __felide_system_win32_processredirector_hpp__
#define __felide_system_win32_processredirector_hpp__

#include <Windows.h>
#include <string>

namespace felide { namespace system { namespace win32 {
    class ProcessRedirector {
    public:
        ProcessRedirector(STARTUPINFO *si, PROCESS_INFORMATION *pi);

        ~ProcessRedirector();

        std::string getOutput();

    private:
        HANDLE hStdIn = 0, hStdOut = 0;
        HANDLE hReadStdOut = 0, hWriteStdIn = 0;
        PROCESS_INFORMATION *pi = nullptr;
    };
}}}

#endif
