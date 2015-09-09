
#include "CTabbedEditorPanel.hpp"
#include "CEditor.hpp"
#include "CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {

    CTabbedEditorPanel::CTabbedEditorPanel(CMainFrame *mainFrame) {
		assert(mainFrame);

		this->mainFrame = mainFrame;
	}

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
	
	BOOL CTabbedEditorPanel::OnCommand(WPARAM wParam, LPARAM lParam) {
		const int notification = HIWORD(wParam);
		const HWND hWnd = reinterpret_cast<HWND>(lParam);

		Editor* editor = dynamic_cast<Editor*>(this->GetMDIChildFromHwnd(hWnd));

		if (editor && notification==EN_CHANGE) {
			editor->getProjectItem()->modify();
			this->mainFrame->getHandler()->handleEditorTitleUpdated(editor);
			
			return TRUE;
		}

		return FALSE;
	}
}}}
