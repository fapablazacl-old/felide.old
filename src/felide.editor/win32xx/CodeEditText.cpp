
#include "CodeEditText.hpp"

namespace felide { namespace editor { namespace win32xx {
	CodeEditText::~CodeEditText() {}

	void CodeEditText::PreCreate(CREATESTRUCT &cs) {
        cs.style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN | ES_LEFT | ES_MULTILINE | WS_VSCROLL | ES_AUTOVSCROLL;
        cs.lpszClass = "EDIT";
    }

	void CodeEditText::SetText(const CString &text) {
	}

	CString CodeEditText::GetText() {
		return "";
	}

	void CodeEditText::SetSavePoint() {
	}

	void CodeEditText::EmptyUndoBuffer() {
	}

	void CodeEditText::ClearAll() {
	}
}}}
