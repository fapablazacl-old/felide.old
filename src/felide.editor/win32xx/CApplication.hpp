
#ifndef __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__

#include <wincore.h>

#include "felide.editor/Application.hpp"
#include "felide.editor/win32xx/CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {
	class CApplication : public felide::editor::Application {
	public:
		virtual int execute(int argc, char **argv) override;
	};
}}}

#endif	// __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
