
#ifndef __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__

#include <memory>
#include <string>
#include <wincore.h>

namespace felide { namespace editor { namespace win32xx { 
    class Module {
    public:
        explicit Module(const std::string &name);
        virtual ~Module();
        void* getAddress(const std::string &procName);

    private:
        HMODULE module = NULL;
    };
    typedef std::unique_ptr<Module> ModulePtr;

}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MODULEWIN32XX_HPP__
