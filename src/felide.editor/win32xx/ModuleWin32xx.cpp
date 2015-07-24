
#include "ModuleWin32xx.hpp"

namespace felide { namespace editor { namespace win32xx { 

    Module::Module(const std::string &name) {
        HMODULE module = ::LoadLibraryA(name.c_str());

        if (!module) {
            throw std::runtime_error("Can't load module '" + name + "'.");
        }

        this->module = module;
    }

    Module::~Module() {
        if (this->module) {
            ::FreeLibrary(this->module);
        }
    }

    void* Module::getAddress(const std::string &procName) {
        return ::GetProcAddress(this->module, procName.c_str());
    }
}}}
