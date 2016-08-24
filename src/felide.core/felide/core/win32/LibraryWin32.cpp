
#include "LibraryWin32.hpp"

namespace felide { namespace core { namespace win32 {

    LibraryWin32::LibraryWin32(const std::string &name) {
        m_name = name;
        m_hModule = ::LoadLibrary(name.c_str());

        if (!m_hModule) {
            throw std::runtime_error("Couldn't load library '" + name + "'");
        }
    }

    LibraryWin32::~LibraryWin32() {
        if (m_hModule) {
            ::FreeLibrary(m_hModule);
        }
    }

    void* LibraryWin32::getAddress(const std::string &procedureName) {
        return ::GetProcAddress(m_hModule, procedureName.c_str());
    }
}}}
