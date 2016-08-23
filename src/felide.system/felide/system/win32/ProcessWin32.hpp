
#ifndef __felide_system_processwin32_hpp__
#define __felide_system_processwin32_hpp__

#include <memory>
#include <list>
#include "../Process.hpp"
#include "ProcessRedirector.hpp"

namespace felide { namespace system { namespace win32 {

    class ProcessRedirector;

    class ProcessWin32 : public Process {
    public:
        ProcessWin32(ProcessFlags flags, const std::string &name);
            
        ProcessWin32(ProcessFlags flags, const std::string &name, const std::list<std::string> &args);

        virtual ~ProcessWin32();

        virtual int getExitCode() const override;

        virtual void wait() override;

        virtual ProcessStatus getStatus() const override;

        virtual void start() override;

        virtual void terminate() override;

        virtual void pause() override;

        virtual std::string getOutput() const override;

    private:
        void construct(ProcessFlags flags, const std::string &name, const std::list<std::string> &args);

    private:
        std::unique_ptr<ProcessRedirector> m_redirector;
        PROCESS_INFORMATION m_processInfo;
    };
}}}

#endif
