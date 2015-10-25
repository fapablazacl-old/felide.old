
#include "CTabbedEditorPanel.hpp"
#include "CEditor.hpp"
#include "CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {

    CTabbedEditorPanel::CTabbedEditorPanel(CMainFrame *mainFrame) {
		assert(this);
		assert(mainFrame);

		this->mainFrame = mainFrame;
	}

    CTabbedEditorPanel::~CTabbedEditorPanel() {}

	CWnd* CTabbedEditorPanel::GetMDIChildFromHwnd(HWND hWnd) {
		assert(this);

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
		assert(this);

		const int notification = HIWORD(wParam);
		const HWND hWnd = reinterpret_cast<HWND>(lParam);

		Editor* editor = dynamic_cast<Editor*>(this->GetMDIChildFromHwnd(hWnd));

		if (editor && notification==EN_CHANGE) {
			editor->getProjectItem()->setModifyFlag(true);
			this->mainFrame->getHandler()->handleEditorChanged(editor);
			
			return TRUE;
		}

		return FALSE;
	}

	void CTabbedEditorPanel::CloseEditor(CEditor* editor) {
		int index = -1;
		bool found = false;

		for (int i=0; i<this->GetMDIChildCount(); ++i) {
			const CWnd *child = this->GetMDIChild(i);

			if (static_cast<CWnd*>(editor) == child) {
				index = i;
				found = true;

				break;
			}
		}

		assert(found);

		this->CloseMDIChild(index);
	}

	CMainFrame* CTabbedEditorPanel::getMainFrame() {
		return this->mainFrame;
	}

	const CMainFrame* CTabbedEditorPanel::getMainFrame() const {
		return this->mainFrame;
	}
}}}
