
#include "CEditorText.hpp"
#include "CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {

    CEditorText::CEditorText(ProjectItemPtr projectItem) : CEditorBase(std::move(projectItem)) {	
	}

    CEditorText::~CEditorText() {}

    void CEditorText::PreCreate(CREATESTRUCT &cs) {
		assert(this);

        cs.style = WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | 
                    ES_AUTOVSCROLL | ES_NOHIDESEL | WS_HSCROLL | WS_VSCROLL;
    }

	void CEditorText::setText(const std::string &text) {
		assert(this);

		CEdit::SetWindowTextA(text.c_str());
	}

    std::string CEditorText::getText() const {
		assert(this);

		return std::string(CEdit::GetWindowTextA());
	}

	void CEditorText::setSavePoint() {
		assert(this);
	}

	void CEditorText::emptyUndoBuffer() {
		assert(this);
	}

	void CEditorText::clearAll() {
		assert(this);

		CEdit::SetWindowTextA("");
	}

	void CEditorText::setFont(const std::string &name, const int size) {
		assert(this);

        this->editorFont.CreatePointFont(size*10, name.c_str());

		CEdit::SetFont(&this->editorFont);
		CEdit::Invalidate();
	}

	void CEditorText::setTabWidth(const int spaces) {
		assert(this);

		const int factor = 4;

		this->SetTabStops(spaces*factor);

		CEdit::Invalidate();
	}

	void CEditorText::undo() {
		this->Undo();
	}

	void CEditorText::redo() {
		// TODO: Implement in some way.
	}

	void CEditorText::cut()  {
		this->Cut();
	}

	void CEditorText::copy() {
		this->Copy();
	}

	void CEditorText::paste() {
		this->Paste();
	}

}}}
