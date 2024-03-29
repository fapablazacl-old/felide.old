
#include "CModule.hpp"

namespace felide { namespace view { namespace win32xx { 

    CModule::CModule(const std::string &name) {
        HMODULE module = ::LoadLibraryA(name.c_str());

        if (!module) {
            throw std::runtime_error("Can't load module '" + name + "'.");
        }
		
        this->module = module;
    }

    CModule::~CModule() {
		::FreeLibrary(this->module);
    }

    void* CModule::getAddress(const std::string &procName) {
        return reinterpret_cast<void*>(::GetProcAddress(this->module, procName.c_str()));
    }
}}}
