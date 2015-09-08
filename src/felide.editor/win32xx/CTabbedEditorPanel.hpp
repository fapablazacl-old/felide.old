
#ifndef __felide_editor_win32xx_tabbededitorpanel_hpp__
#define __felide_editor_win32xx_tabbededitorpanel_hpp__

#include <toolbar.h>
#include <tab.h>

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel : public CTabbedMDI {
	public:
		const int ID_MDI_EDITOR = 1;

	public:
        CTabbedEditorPanel();
		virtual ~CTabbedEditorPanel();

		virtual LRESULT OnNotify(WPARAM wParam, LPARAM lParam) override;

		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;

		CWnd* GetMDIChildFromHwnd(HWND hWnd);
	};
}}}

#endif // __felide_editor_win32xx_tabbededitorpanel_hpp__
