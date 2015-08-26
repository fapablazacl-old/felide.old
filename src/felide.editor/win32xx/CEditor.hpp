
#ifndef __felide_editor_win32xx_ceditor_hpp__
#define __felide_editor_win32xx_ceditor_hpp__

#include "CEditorSci.hpp"
#include "CEditorText.hpp"

namespace felide { namespace editor { namespace win32xx {

#if defined(FELIDE_GUI_CODEEDIT_SCI)
	typedef CEditorSci CEditor;
#else 
	typedef CEditorText CEditor;
#endif

}}}

#endif	// __felide_editor_win32xx_ceditor_hpp__
