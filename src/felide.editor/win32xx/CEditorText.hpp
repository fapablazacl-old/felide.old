
#ifndef __felide_editor_win32xx_editortext_hpp__
#define __felide_editor_win32xx_editortext_hpp__

#include <wincore.h>
#include <stdcontrols.h>

#include "felide/ProjectItem.hpp"
#include "felide.editor/Editor.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CEditorText : public Editor, CEdit {
	public:
        CEditorText(ProjectItemPtr projectItem);
		virtual ~CEditorText();

        // 

        virtual void PreCreate(CREATESTRUCT &cs) override;

        // 

		virtual void setText(const std::string &text) override;
        virtual std::string getText() const override;

        virtual void setSavePoint() override;
        virtual void emptyUndoBuffer() override;
        virtual void clearAll() override;

		virtual void setFont(const std::string &name, const int size) override;
		virtual void setTabWidth(const int spaces) override;

		virtual ProjectItem* getProjectItem() override;

		virtual const ProjectItem* getProjectItem() const override;

	private:
		ProjectItemPtr projectItem;
        CFont editorFont;
	};
}}}

#endif	// __felide_editor_win32xx_editortext_hpp__
