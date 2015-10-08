
#ifndef __felide_editor_win32xx_tabbededitorpanel_hpp__
#define __felide_editor_win32xx_tabbededitorpanel_hpp__

#include <toolbar.h>
#include <tab.h>

namespace felide {  namespace editor {  namespace win32xx {

	class CEditor;
	class CMainFrame;
	class CTabbedEditorPanel : public CTabbedMDI {
	public:
		const int ID_MDI_EDITOR = 1;

	public:
		explicit CTabbedEditorPanel(CMainFrame *mainframe);
		virtual ~CTabbedEditorPanel();

		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;

		CWnd* GetMDIChildFromHwnd(HWND hWnd);

		void CloseEditor(CEditor* editor);

		CMainFrame *getMainFrame();

		const CMainFrame *getMainFrame() const;

	private:
		CMainFrame *mainFrame = nullptr;
	};
}}}

#endif // __felide_editor_win32xx_tabbededitorpanel_hpp__
