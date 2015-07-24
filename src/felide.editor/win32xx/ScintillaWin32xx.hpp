
#ifndef __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__
#define __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__

#include <string>
#include <wincore.h>
#include <Scintilla.h>
#include <SciLexer.h>

namespace felide { namespace editor { namespace win32xx { 
    class Scintilla : public CWnd {
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
        void SetText(const CString &text) {
            this->SendEditor(SCI_SETTEXT, 0, (LPARAM)text.c_str());
        }

        CString GetText() {
            std::string content;
            const int length = this->SendEditor(SCI_GETTEXTLENGTH);
            content.resize(length);
            this->SendEditor(SCI_GETTEXT, length, (LPARAM)content.c_str());

            return content.c_str();
        }

        void SetSavePoint() {
            this->SendEditor(SCI_SETSAVEPOINT);
        }

        void EmptyUndoBuffer() {
            this->SendEditor(SCI_EMPTYUNDOBUFFER);
        }

        void ClearAll() { 
            this->SendEditor(SCI_CLEARALL);
        }
    };
}}}

#endif // __FELIDE_EDITOR_WIN32XX_SCINTILLA_HPP__
