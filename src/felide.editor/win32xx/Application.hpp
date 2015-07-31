
#ifndef __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__

#include <wincore.h>
#include "MainFrame.hpp"
#include "Module.hpp"
#include "felide.editor/Application.hpp"

namespace felide { namespace editor { namespace win32xx {
	class Application : public felide::editor::Application {
	public:
		virtual int getReturnCode() override;
	};
}}}

#endif	// __FELIDE_EDITOR_WIN32XX_APPLICATIONWIN32XX_HPP__
