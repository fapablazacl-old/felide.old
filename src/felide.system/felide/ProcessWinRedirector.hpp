
#ifndef __felide_core_win32_processredirector_hpp__
#define __felide_core_win32_processredirector_hpp__

#include <Windows.h>
#include <string>

namespace felide {
    class ProcessWinRedirector {
    public:
        ProcessWinRedirector(STARTUPINFO *si, PROCESS_INFORMATION *m_pi);

        ~ProcessWinRedirector();

        std::string getOutput();

    private:
        HANDLE m_hStdIn = 0, m_hStdOut = 0;
        HANDLE m_hReadStdOut = 0, m_hWriteStdIn = 0;
        PROCESS_INFORMATION *m_pi = nullptr;
    };
}

#endif
