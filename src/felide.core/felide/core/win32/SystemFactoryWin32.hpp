
#ifndef __felide_core_win32_systemfactorywin32_hpp__
#define __felide_core_win32_systemfactorywin32_hpp__

#include <memory>
#include <vector>

#include "../SystemFactory.hpp"

namespace felide { namespace core { namespace win32 {

    class Library;
    class Process;

    class SystemFactoryWin32 : public SystemFactory {
    public:
        virtual ~SystemFactoryWin32();

        virtual std::unique_ptr<Process> createProcess(const std::string &name, const std::vector<std::string> &args) override;

        virtual std::unique_ptr<Library> loadLibrary(const std::string &name) override;
    };
}}}

#endif 
