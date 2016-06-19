
#include "CEditorBase.hpp"

// #include "felide.editor/win32xx/CTabbedEditorPanel.hpp"

namespace felide { namespace view { namespace win32xx {

	CEditorBase::CEditorBase(ProjectItemPtr projectItem) {
		this->projectItem = std::move(projectItem);
	}

	ProjectItem* CEditorBase::getProjectItem() {
		return this->projectItem.get();
	}

	const ProjectItem* CEditorBase::getProjectItem() const {
		return this->projectItem.get();
	}

	/*
	void CEditorBase::setTitle(const std::string &title) {
		assert(this);
		
		CTab *tab = this->GetEditorPanel()->GetTab();

		const int tabIndex = tab->GetTabIndex(static_cast<CWnd*>(this));
		tab->SetTabText(tabIndex, title.c_str());
		this->GetEditorPanel()->RecalcLayout();
		
	}
	*/

	void CEditorBase::SetEditorPanel(CTabbedEditorPanel *editorPanel) {
		this->editorPanel = editorPanel;
	}

	CTabbedEditorPanel* CEditorBase::GetEditorPanel() {
		return this->editorPanel;
	}

	const CTabbedEditorPanel* CEditorBase::GetEditorPanel() const {
		return this->editorPanel;
	}
}}}
