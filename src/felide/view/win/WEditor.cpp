
#include "WEditor.hpp"

namespace felide { namespace view { namespace win {

	WEditor::WEditor(ProjectItemPtr item) {
		m_item = std::move(item);
	}

	void WEditor::setText(const std::string &text) {
		this->SetText(text);
	}

	std::string WEditor::getText() const {
		return this->GetText();
	}

	void WEditor::setSavePoint() {
		this->SetSavePoint();
	}

	void WEditor::emptyUndoBuffer() {
		this->EmptyUndoBuffer();
	}

	void WEditor::clearAll() {
		this->ClearAll();
	}

	void WEditor::setTabWidth(const int spaces) {
		this->SetTabWidth(spaces);
	}

	void WEditor::setFont(const std::string &name, const int size) {
		//! TODO: Add custom code here
	}

	ProjectItem* WEditor::getProjectItem() {
		return m_item.get();
	}

	const ProjectItem* WEditor::getProjectItem() const {
		return m_item.get();
	}

	void WEditor::undo() {
		this->Undo();
	}

	void WEditor::redo() {
		this->Redo();
	}

	void WEditor::cut() {
		this->Cut();
	}

	void WEditor::copy() {
		this->Copy();
	}

	void WEditor::paste() {
		this->Paste();
	}
}}}
