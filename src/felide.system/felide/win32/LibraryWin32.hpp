
#ifndef __felide_core_win32_librarywin32_hpp__
#define __felide_core_win32_librarywin32_hpp__

#include "../Library.hpp"

#include <Windows.h>

namespace felide {
    class LibraryWin32 : public Library {
    public:
        LibraryWin32(const std::string &name);

        virtual ~LibraryWin32();

        virtual void* getAddress(const std::string &procedureName) override;

    private:
        std::string m_name;
        HMODULE m_hModule = nullptr;
    };
}

#endif
