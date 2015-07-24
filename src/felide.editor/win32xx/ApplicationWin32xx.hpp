
#ifndef __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__

#include <wincore.h>
#include "MainFrameWin32xx.hpp"
#include "ModuleWin32xx.hpp"

namespace felide { namespace editor { namespace win32xx {
	
	class ApplicationWin32xx : public CWinApp {
	public:
        virtual BOOL InitInstance() override;

    private:
        MainFrameWin32xx mainFrame;
        ModulePtr scintillaModule;
	};
}}}

#endif	// __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
