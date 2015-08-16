
#ifndef __felide_editor_win32xx_editortext_hpp__
#define __felide_editor_win32xx_editortext_hpp__

#include <wincore.h>
#include <stdcontrols.h>

#include "CEditor.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CustomEdit;

	class CEditorText : public CEditor {
	public:
        CEditorText(ProjectItemPtr projectItem);
		virtual ~CEditorText();

		virtual CWnd* getWindow() override;

		virtual void SetText(const CString &text) override;
        virtual CString GetText() override;

        virtual void SetSavePoint() override;
        virtual void EmptyUndoBuffer() override;
        virtual void ClearAll() override;

		virtual void setFont(const CString &name, const int size) override;
		virtual void setTabWidth(const int spaces) override;

		virtual ProjectItem* getProjectItem() override;

		virtual const ProjectItem* getProjectItem() const override;

	private:
		std::unique_ptr<CustomEdit> edit;
		ProjectItemPtr projectItem;
	};
}}}

#endif	// __felide_editor_win32xx_editortext_hpp__
