
#include "CEditorText.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CustomEdit : public CEdit {
	public:
		CustomEdit() {}

		virtual void PreCreate(CREATESTRUCT &cs) override {
			cs.style = WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_NOHIDESEL | WS_HSCROLL | WS_VSCROLL;
		}

		CFont *getFont() {
			return &this->font;
		}

	private:
		CFont font;
	};

    CEditorText::CEditorText(ProjectItemPtr projectItem) : edit(new CustomEdit()) {
		this->projectItem = std::move(projectItem);
	}

    CEditorText::~CEditorText() {}

	void CEditorText::SetText(const CString &text) {
		this->edit->SetWindowTextA(text);
	}

	CString CEditorText::GetText() {
		return this->edit->GetWindowTextA();
	}

	void CEditorText::SetSavePoint() {}

	void CEditorText::EmptyUndoBuffer() {}

	void CEditorText::ClearAll() {
		this->edit->SetWindowTextA("");
	}

	CWnd* CEditorText::getWindow() {
		return this->edit.get();
	}

	void CEditorText::setFont(const CString &name, const int size) {

		this->edit->getFont()->CreatePointFont(size*10, name);

		this->edit->SetFont(this->edit->getFont());
		this->edit->Invalidate();
	}

	void CEditorText::setTabWidth(const int spaces) {
		const int factor = 4;

		this->edit->SetTabStops(spaces*factor);
		this->edit->Invalidate();
	}

	ProjectItem* CEditorText::getProjectItem() {
		return this->projectItem.get();
	}

	const ProjectItem* CEditorText::getProjectItem() const {
		return this->projectItem.get();
	}
}}}
