
#include "CodeEditText.hpp"

namespace felide { namespace editor { namespace win32xx {
	CodeEditText::~CodeEditText() {}

	void CodeEditText::PreCreate(CREATESTRUCT &cs) {
        cs.style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN | ES_LEFT | ES_MULTILINE | WS_VSCROLL | ES_AUTOVSCROLL;
        cs.lpszClass = "EDIT";
    }

	void CodeEditText::SetText(const CString &text) {
		this->SendMessageA(WM_SETTEXT, 0, (LPARAM)text.c_str());
	}

	CString CodeEditText::GetText() {
		INT textLength = this->SendMessageA(WM_GETTEXTLENGTH, 0, 0);

		std::string text;
		text.resize(textLength);

		this->SendMessageA(WM_GETTEXT, 0, (LPARAM)text.c_str());
		
		return text.c_str();
	}

	void CodeEditText::SetSavePoint() {
	}

	void CodeEditText::EmptyUndoBuffer() {
	}

	void CodeEditText::ClearAll() {
	}
}}}
