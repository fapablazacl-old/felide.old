
#include "CTabbedEditorPanel.hpp"
#include "CEditor.hpp"
#include "CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {
    CTabbedEditorPanel::CTabbedEditorPanel() {}
    CTabbedEditorPanel::~CTabbedEditorPanel() {}

	CWnd* CTabbedEditorPanel::GetMDIChildFromHwnd(HWND hWnd) {
		CWnd* result = nullptr;

		for (int i=0; i<this->GetMDIChildCount(); ++i) {

			CWnd *child = this->GetMDIChild(i);

			if (child->GetHwnd() == hWnd) {
				result = child;
				break;
			}
		}

		return result;
	}

	LRESULT CTabbedEditorPanel::OnNotify(WPARAM wParam, LPARAM lParam) {
		NMHDR* nmhdr = reinterpret_cast<NMHDR*>(lParam);

		switch (nmhdr->code) {

			case EN_CHANGE: 
			{
				HWND hWnd = ((NMHDR*)lParam)->hwndFrom;
				Editor* editor = dynamic_cast<Editor*>(this->GetMDIChildFromHwnd(hWnd));
			}

			default:
				break;
		}

		return 0;
	}

	BOOL CTabbedEditorPanel::OnCommand(WPARAM wParam, LPARAM lParam) {
		const int notification = HIWORD(wParam);
		const HWND hWnd = reinterpret_cast<HWND>(lParam);

		Editor* editor = dynamic_cast<Editor*>(this->GetMDIChildFromHwnd(hWnd));

		if (editor && notification==EN_CHANGE) {
			CMainFrame *mainFrame = dynamic_cast<CMainFrame *>(this->GetParent());

			mainFrame->getHandler()->handleEditorTitleUpdated(editor);
			
			return TRUE;
		}

		return FALSE;
	}
}}}
