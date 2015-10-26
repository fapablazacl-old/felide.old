
#if defined(FELIDE_GUI_CODEEDIT_SCI)

#ifndef __felide_editor_win32xx_editorsci_hpp__
#define __felide_editor_win32xx_editorsci_hpp__

#include "felide/view/Editor.hpp"
#include "CEditorBase.hpp"

#include <string>
#include <wincore.h>
#include <Scintilla.h>
#include <SciLexer.h>

namespace felide { namespace editor { namespace win32xx { 

    class CEditorSci : public virtual CEditorBase, public virtual CWnd {
    public:
		CEditorSci(ProjectItemPtr projectItem);

        virtual void PreCreate(CREATESTRUCT &cs) override;

        virtual void OnInitialUpdate() override;

        LRESULT SendEditor(UINT Msg) const;
        LRESULT SendEditor(UINT Msg, WPARAM wParam) const;
        LRESULT SendEditor(UINT Msg, WPARAM wParam, LPARAM lParam) const;

        void SetAStyle(int style, COLORREF fore);
        void SetAStyle(int style, COLORREF fore, COLORREF back);
        void SetAStyle(int style, COLORREF fore, COLORREF back, int size);
        void SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char *face);

    public:
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
    };
}}}

#endif // __felide_editor_win32xx_editorsci_hpp__

#endif	// 
