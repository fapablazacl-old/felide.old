
#if defined(FELIDE_GUI_CODEEDIT_SCI)

#ifndef __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__
#define __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__

#include "CodeEdit.hpp"

#include <string>
#include <wincore.h>
#include <Scintilla.h>
#include <SciLexer.h>

namespace felide { namespace editor { namespace win32xx { 
    class Scintilla : public CodeEdit {
    public:
        virtual void PreCreate(CREATESTRUCT &cs) override;

        virtual void OnInitialUpdate() override;

        LRESULT SendEditor(UINT Msg);
        LRESULT SendEditor(UINT Msg, WPARAM wParam);
        LRESULT SendEditor(UINT Msg, WPARAM wParam, LPARAM lParam);

        void SetAStyle(int style, COLORREF fore);
        void SetAStyle(int style, COLORREF fore, COLORREF back);
        void SetAStyle(int style, COLORREF fore, COLORREF back, int size);
        void SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char *face);

    public:
        virtual void SetText(const CString &text) {
            this->SendEditor(SCI_SETTEXT, 0, (LPARAM)text.c_str());
        }

        virtual CString GetText() override {
            std::string content;
            const int length = this->SendEditor(SCI_GETTEXTLENGTH);
            content.resize(length);
            this->SendEditor(SCI_GETTEXT, length, (LPARAM)content.c_str());

            return content.c_str();
        }

        virtual void SetSavePoint() override {
            this->SendEditor(SCI_SETSAVEPOINT);
        }

        virtual void EmptyUndoBuffer() override {
            this->SendEditor(SCI_EMPTYUNDOBUFFER);
        }

        virtual void ClearAll() override { 
            this->SendEditor(SCI_CLEARALL);
        }
    };
}}}

#endif // __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__

#endif	
