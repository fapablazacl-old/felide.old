
#ifndef __felide_editor_win32xx_ceditorbase_hpp__
#define __felide_editor_win32xx_ceditorbase_hpp__

// #include "CEditorSci.hpp"
// #include "CEditorText.hpp"

#include <wincore.h>
#include "felide.editor/Editor.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel;
	class CEditorBase : public Editor {
	public:
		CEditorBase(ProjectItemPtr projectItem);

		virtual ProjectItem* getProjectItem() override;
		virtual const ProjectItem* getProjectItem() const override;

		void SetEditorPanel(CTabbedEditorPanel *editorPanel);

		CTabbedEditorPanel *GetEditorPanel();

		const CTabbedEditorPanel *GetEditorPanel() const;

	private:
		ProjectItemPtr projectItem;
		CTabbedEditorPanel *editorPanel = nullptr;
	};
}}}

#endif	// __felide_editor_win32xx_ceditor_hpp__
