#pragma once

#include <wcl/Scintilla.hpp>

#include "felide/ProjectItem.hpp"
#include "felide/view/Editor.hpp"

namespace felide { namespace view { namespace win {
    class WEditor : public wcl::Scintilla, public Editor {
    public:
        explicit WEditor(ProjectItemPtr item);

    public:
        virtual LRESULT Procedure(UINT Msg, WPARAM wParam, LPARAM lParam);

    public:

        virtual void setText(const std::string &text) override {
            this->SetText(text);
        }

        virtual std::string getText() const override {
	    return this->GetText();
        }

        virtual void setSavePoint() override {
	    this->SetSavePoint();
        }

        virtual void emptyUndoBuffer() override {
	    this->EmptyUndoBuffer();
        }

        virtual void clearAll() override {
	    this->ClearAll();
        }

        virtual void setTabWidth(const int spaces) override {
	    this->SetTabWidth(spaces);
        }

        virtual ProjectItem* getProjectItem() override {
            return m_item.get();
        }

        virtual const ProjectItem* getProjectItem() const override {
            return m_item.get();
        }

        virtual void undo() override {
            this->Undo();
        }

        virtual void redo() override {
            this->Redo();
        }

        virtual void cut() override {
	    this->Cut();
        }

        virtual void copy() override {
	    this->Copy();
        }

        virtual void paste() override {
	    this->Paste();
        }
        
        virtual void setLexer(const Lexer &lexer) override;

    private:
        ProjectItemPtr m_item;
    };
}}}
