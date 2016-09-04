
#ifndef __felide_core_systemfactory_hpp__
#define __felide_core_systemfactory_hpp__

#include <memory>
#include <list>

#include "Process.hpp"
#include "Library.hpp"

namespace felide {
    class SystemFactory {
    public:
        virtual ~SystemFactory();

        virtual std::unique_ptr<Process> createProcess(ProcessFlags flags, const std::string &name, const std::list<std::string> &args) = 0;

        virtual std::unique_ptr<Library> loadLibrary(const std::string &name) = 0;

    public:
        static std::unique_ptr<SystemFactory> newInstance();
    };
}

#endif 
