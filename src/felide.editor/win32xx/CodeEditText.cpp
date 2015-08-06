
#include "CodeEditText.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CustomEdit : public CEdit {
	public:
		CustomEdit() {
			
		}

		virtual void PreCreate(CREATESTRUCT &cs) override {
			cs.style = WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_NOHIDESEL | WS_HSCROLL | WS_VSCROLL;
		}

		CFont *getFont() {
			return &this->font;
		}

	private:
		CFont font;
	};

	CodeEditText::CodeEditText() : edit(new CustomEdit()) {}

	CodeEditText::~CodeEditText() {}

	void CodeEditText::SetText(const CString &text) {
		this->edit->SetWindowTextA(text);
	}

	CString CodeEditText::GetText() {
		return this->edit->GetWindowTextA();
	}

	void CodeEditText::SetSavePoint() {}

	void CodeEditText::EmptyUndoBuffer() {}

	void CodeEditText::ClearAll() {
		this->edit->SetWindowTextA("");
	}

	CWnd* CodeEditText::getWindow() {
		return this->edit.get();
	}

	void CodeEditText::setFont(const CString &name, const int size) {

		this->edit->getFont()->CreatePointFont(size*10, name);

		this->edit->SetFont(this->edit->getFont());
		this->edit->Invalidate();
	}

	void CodeEditText::setTabWidth(const int spaces) {
		const int factor = 4;

		this->edit->SetTabStops(spaces*factor);
		this->edit->Invalidate();
	}
}}}
