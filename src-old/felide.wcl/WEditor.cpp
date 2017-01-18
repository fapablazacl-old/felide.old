
#include "WEditor.hpp"

#include <iostream>
#include <boost/algorithm/string/join.hpp>

namespace felide { namespace view { namespace win {

    WEditor::WEditor(ProjectItemPtr item) {
        m_item = std::move(item);
    }

    LRESULT WEditor::Procedure(UINT Msg, WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
    case WM_CHAR:
            m_item->setModifyFlag(true);
        break;
    }

    return Scintilla::Procedure(Msg, wParam, lParam);
    }

    void WEditor::setLexer(const Lexer &lexer) {
        std::string keywords = boost::join(lexer.keywords, " ");
        
        //! TODO: Grab the font name from elsewhere
        this->SetStyle(STYLE_DEFAULT, RGB(0, 0, 0), RGB(255, 255, 255), 10, "Courier New");
        this->SendMessage_(SCI_STYLECLEARALL);
        this->SendMessage_(SCI_SETLEXER, lexer.name);
        this->SendMessage_(SCI_SETSTYLEBITS, 7);
        this->SendMessage_(SCI_SETKEYWORDS, 0, (LPARAM)keywords.c_str());
        this->SendMessage_(SCI_SETUSETABS, 0);
    this->SendMessage_(SCI_SETTABWIDTH, 4);

        for (const auto &pair : lexer.colors) {
            const Color c = pair.second;

            this->SetStyle(pair.first, RGB(c.r, c.g, c.b));
        }
    }
}}}
