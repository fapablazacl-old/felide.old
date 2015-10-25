
#ifndef __felide_editor_win32xx_editortext_hpp__
#define __felide_editor_win32xx_editortext_hpp__

#include <wincore.h>
#include <stdcontrols.h>
#include <mdi.h>

#include "felide/ProjectItem.hpp"
#include "felide.editor/win32xx/CEditorBase.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel;
	class CEditorText : public CEditorBase, public CEdit {
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

		virtual void undo() override;
		virtual void redo() override;

		virtual void cut() override;
		virtual void copy() override;
		virtual void paste() override;

	private:
        CFont editorFont;
	};
}}}

#endif	// __felide_editor_win32xx_editortext_hpp__
