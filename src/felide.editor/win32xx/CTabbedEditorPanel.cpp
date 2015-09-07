
#include "CTabbedEditorPanel.hpp"

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
}}}
