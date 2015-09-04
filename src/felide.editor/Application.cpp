
#include "Application.hpp"

#if defined(FELIDE_GUI_TOOLKIT_QT5)
#include "qt5/QApplication.hpp"
typedef felide::editor::qt5::Application ApplicationImpl;
#elif defined(FELIDE_GUI_TOOLKIT_WIN32XX)
#include "win32xx/CApplication.hpp"
typedef felide::editor::win32xx::CApplication ApplicationImpl;
#else
#error You must select first a GUI toolkit.
#endif

namespace felide { namespace editor {
	Application::~Application() {}

	ApplicationPtr Application::new_() {
		return ApplicationPtr(new ApplicationImpl());
	}
}}
