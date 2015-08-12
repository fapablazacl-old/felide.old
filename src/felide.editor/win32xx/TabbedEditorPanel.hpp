
#ifndef __felide_editor_win32xx_tabbededitorpanel_hpp__
#define __felide_editor_win32xx_tabbededitorpanel_hpp__

#include <toolbar.h>
#include <tab.h>

namespace felide { namespace editor { namespace win32xx {

	class Editor;
	class TabbedEditorPanel : public CTabbedMDI {
	public:
		const int ID_MDI_EDITOR = 1;

	public:
		TabbedEditorPanel();
		virtual ~TabbedEditorPanel();
	};
}}}

#endif // __felide_editor_win32xx_tabbededitorpanel_hpp__
