
#ifndef __felide_system_process_hpp__
#define __felide_system_process_hpp__

#include <string>

namespace felide { namespace system {

    enum class ProcessStatus {
        Stopped,     //! The process has not begun, or has been terminated.
        Executing     //! The process is currently executing.
    }; 

    enum class ProcessFlags {
        Default,
        Redirect
    };

    inline bool operator& (ProcessFlags flags, ProcessFlags flag) {
        if (static_cast<int>(flags)&static_cast<int>(flag)) {
            return true;
        } else {
            return false;
        }
    }

    class Process {
    public:
        virtual ~Process();

        virtual int getExitCode() const = 0;

        virtual ProcessStatus getStatus() const = 0;

        virtual void start() = 0;

        virtual void terminate() = 0;

        virtual void pause() = 0;

        virtual void wait() = 0;

        virtual std::string getOutput() const = 0;
    };
}}

#endif
