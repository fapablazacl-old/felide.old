
#ifndef __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__

#include <memory>
#include <string>
#include <wincore.h>

namespace felide { namespace editor { namespace win32xx { 
    class CModule {
    public:
        explicit CModule(const std::string &name);
        virtual ~CModule();
        void* getAddress(const std::string &procName);

    private:
        HMODULE module = nullptr;
    };
    typedef std::unique_ptr<CModule> CModulePtr;

}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__
