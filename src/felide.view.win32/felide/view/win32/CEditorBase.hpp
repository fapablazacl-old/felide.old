
#ifndef __felide_editor_win32xx_ceditorbase_hpp__
#define __felide_editor_win32xx_ceditorbase_hpp__

#include <wincore.h>

#include "CEditor.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel;
	class CEditorBase : public virtual CEditor {
	public:
		CEditorBase(ProjectItemPtr projectItem);

		virtual ProjectItem* getProjectItem() override;
		virtual const ProjectItem* getProjectItem() const override;

		// virtual void setTitle(const std::string &title) override;

	public:
		virtual void SetEditorPanel(CTabbedEditorPanel *editorPanel) override;
		virtual CTabbedEditorPanel *GetEditorPanel() override;
		virtual const CTabbedEditorPanel *GetEditorPanel() const override;

	private:
		ProjectItemPtr projectItem;
		CTabbedEditorPanel *editorPanel = nullptr;
	};
}}}

#endif	// __felide_editor_win32xx_ceditor_hpp__
