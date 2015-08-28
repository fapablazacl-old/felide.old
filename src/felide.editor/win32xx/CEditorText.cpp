
#include "CEditorText.hpp"

namespace felide { namespace editor { namespace win32xx {

    CEditorText::CEditorText(ProjectItemPtr projectItem) {
		this->projectItem = std::move(projectItem);
	}

    CEditorText::~CEditorText() {}

    void CEditorText::PreCreate(CREATESTRUCT &cs) {
        cs.style = WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | 
                    ES_AUTOVSCROLL | ES_NOHIDESEL | WS_HSCROLL | WS_VSCROLL;
    }

	void CEditorText::setText(const std::string &text) {
		this->SetWindowTextA(text.c_str());
	}

    std::string CEditorText::getText() const {
		return std::string(this->GetWindowTextA());
	}

	void CEditorText::setSavePoint() {}

	void CEditorText::emptyUndoBuffer() {}

	void CEditorText::clearAll() {
		this->SetWindowTextA("");
	}

	void CEditorText::setFont(const std::string &name, const int size) {
        this->editorFont.CreatePointFont(size*10, name.c_str());

		this->SetFont(&this->editorFont);
		this->Invalidate();
	}

	void CEditorText::setTabWidth(const int spaces) {
		const int factor = 4;

		this->SetTabStops(spaces*factor);
		this->Invalidate();
	}

	ProjectItem* CEditorText::getProjectItem() {
		return this->projectItem.get();
	}

	const ProjectItem* CEditorText::getProjectItem() const {
		return this->projectItem.get();
	}

	void CEditorText::setTitle(const std::string &title) {
		this->GetParent()->SetWindowTextA(title.c_str());
	}

	void CEditorText::SetTabbedMDI(CTabbedMDI *tabbedMdi) {
		this->tabbedMdi = tabbedMdi;
	}
}}}
