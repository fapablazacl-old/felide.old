
#include "CEditorBase.hpp"

namespace felide { namespace editor { namespace win32xx {

	CEditorBase::CEditorBase(ProjectItemPtr projectItem) {
		this->projectItem = std::move(projectItem);
	}

	ProjectItem* CEditorBase::getProjectItem() {
		return this->projectItem.get();
	}

	const ProjectItem* CEditorBase::getProjectItem() const {
		return this->projectItem.get();
	}

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
