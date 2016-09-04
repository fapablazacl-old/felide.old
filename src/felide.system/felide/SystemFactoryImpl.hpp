
#ifndef __felide_core_systemfactoryimpl_hpp__
#define __felide_core_systemfactoryimpl_hpp__

#include <memory>

#include "SystemFactory.hpp"

namespace felide {
    template<typename ProcessImpl, typename LibraryImpl>
    class SystemFactoryImpl : public SystemFactory  {
    public:
        virtual ~SystemFactoryImpl() {}

        virtual std::unique_ptr<Process> createProcess(ProcessFlags flags, const std::string &name, const std::list<std::string> &args) override {
            return std::make_unique<ProcessImpl>(flags, name, args);
        }

        virtual std::unique_ptr<Library> loadLibrary(const std::string &name) override {
            return std::make_unique<LibraryImpl>(name);
        }
    };
}

#endif 
