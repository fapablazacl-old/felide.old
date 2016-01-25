
#if defined(FELIDE_GUI_CODEEDIT_SCI)

#include "CEditorSci.hpp"

#include <Scintilla.h>
#include <SciLexer.h>
#include <map>

namespace felide { namespace editor { namespace win32xx { 

    const COLORREF black = RGB(0,0,0);
    const COLORREF white = RGB(0xff, 0xff, 0xff);

    const char cpp_keywords[] = 
        "alignas alignof and and_eq asm auto bitand bitor bool break case catch "
        "char char16_t char32_t class compl concept const constexpr  const_cast "
        "continue decltype default delete do double dynamic_cast else enum explicit "
        "export extern false float for friend goto if inline int long mutable "
        "namespace new noexcept not not_eq nullptr operator or or_eq private "
        "protected public register reinterpret_cast requires return short "
        "signed sizeof static static_assert static_cast struct switch template this "
        "thread_local throw true try typedef typeid typename union unsigned "
        "using virtual void volatile wchar_t while xor xor_eq "
        "override final ";


	CEditorSci::CEditorSci(ProjectItemPtr projectItem) : CEditorBase(std::move(projectItem)) {
	}

    void CEditorSci::PreCreate(CREATESTRUCT &cs) {
        cs.style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN;
        cs.lpszClass = "Scintilla";
    }

    void CEditorSci::SetAStyle(int style, COLORREF fore) {
        this->SetAStyle(style, fore, white, -1, nullptr);
    }

    void CEditorSci::SetAStyle(int style, COLORREF fore, COLORREF back) {
        this->SetAStyle(style, fore, back, -1, nullptr);
    }

    void CEditorSci::SetAStyle(int style, COLORREF fore, COLORREF back, int size) {
        this->SetAStyle(style, fore, back, size, nullptr);
    }

    void CEditorSci::SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char *face) {
	    this->SendEditor(SCI_STYLESETFORE, style, fore);
	    this->SendEditor(SCI_STYLESETBACK, style, back);

	    if (size >= 1) {
		    SendEditor(SCI_STYLESETSIZE, style, size);
        }

	    if (face) {
		    SendEditor(SCI_STYLESETFONT, style, reinterpret_cast<LPARAM>(face));
        }
    }

    LRESULT CEditorSci::SendEditor(UINT Msg) const {
        return this->SendEditor(Msg, 0, 0);
    }

    LRESULT CEditorSci::SendEditor(UINT Msg, WPARAM wParam) const {
        return this->SendEditor(Msg, wParam, 0);
    }

    LRESULT CEditorSci::SendEditor(UINT Msg, WPARAM wParam, LPARAM lParam) const {
        return this->SendMessage(Msg, wParam, lParam);
    }

    void CEditorSci::OnInitialUpdate() {
	    this->SetAStyle(STYLE_DEFAULT, black, white, 10, "Courier New");
	    this->SendEditor(SCI_STYLECLEARALL);

        this->SendEditor(SCI_SETLEXER, SCLEX_CPP);
        this->SendEditor(SCI_SETSTYLEBITS, 7);
	    this->SendEditor(SCI_SETKEYWORDS, 0, (LPARAM)(cpp_keywords));
   
        /*
        const COLORREF red = RGB(0xFF, 0, 0);
	    const COLORREF darkGreen = RGB(0, 0x80, 0);
	    const COLORREF darkBlue = RGB(0, 0, 0x80);
        */

	    this->SetAStyle(SCE_C_DEFAULT, black, white, 10, "Courier New");

        std::map<int, COLORREF> colors = {
            {SCE_C_COMMENT, RGB(0x00, 0x80, 0x00)}, 
            {SCE_C_COMMENTLINE, RGB(0x00, 0x80, 0x00)}, 
            {SCE_C_COMMENTDOC, RGB(0x00, 0x80, 0x00)}, 
            {SCE_C_NUMBER, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_WORD, RGB(0x00, 0x00, 0xFF)}, 
            {SCE_C_STRING, RGB(0x80, 0x00, 0x00)}, 
            {SCE_C_CHARACTER, RGB(0x80, 0x00, 0x00)}, 
            {SCE_C_UUID, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_PREPROCESSOR, RGB(0xA0, 0x00, 0xFF)}, 
            {SCE_C_OPERATOR, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_IDENTIFIER, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_STRINGEOL, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_VERBATIM, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_REGEX, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_COMMENTLINEDOC, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_WORD2, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_COMMENTDOCKEYWORD, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_COMMENTDOCKEYWORDERROR, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_GLOBALCLASS, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_STRINGRAW, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_TRIPLEVERBATIM, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_HASHQUOTEDSTRING, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_PREPROCESSORCOMMENT, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_PREPROCESSORCOMMENTDOC, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_USERLITERAL, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_TASKMARKER, RGB(0x00, 0x00, 0x00)}, 
            {SCE_C_ESCAPESEQUENCE, RGB(0x00, 0x00, 0x00)}
        };

        for (auto styleIt=colors.begin(); styleIt!=colors.end(); styleIt++) {
            this->SetAStyle(styleIt->first, styleIt->second);
        }

        this->SendEditor(SCI_STYLESETBOLD, SCE_C_WORD, 1);
        this->SendEditor(SCI_STYLESETBOLD, SCE_C_WORD2, 1);
        this->SendEditor(SCI_SETTABWIDTH, 4);
        this->SendEditor(SCI_SETUSETABS, 0);
    }

    void CEditorSci::setText(const std::string &text) {
        this->SendEditor(SCI_SETTEXT, 0, (LPARAM)text.c_str());
    }

    std::string CEditorSci::getText() const {
        std::string content;
        const int length = this->SendEditor(SCI_GETTEXTLENGTH);
        content.resize(length);
        this->SendEditor(SCI_GETTEXT, length, (LPARAM)content.c_str());

        return content;
    }

    void CEditorSci::setSavePoint() {
        this->SendEditor(SCI_SETSAVEPOINT);
    }

    void CEditorSci::emptyUndoBuffer() {
        this->SendEditor(SCI_EMPTYUNDOBUFFER);
    }

    void CEditorSci::clearAll() { 
        this->SendEditor(SCI_CLEARALL);
    }

	void CEditorSci::setFont(const std::string &name, const int size) {

	}

	void CEditorSci::setTabWidth(const int spaces) {
	}

	void CEditorSci::undo() {
	}
	
	void CEditorSci::redo() {

	}

	void CEditorSci::cut() {

	}
	
	void CEditorSci::copy() {
	}

	void CEditorSci::paste() {

	}
}}}

#endif 