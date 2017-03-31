
#ifndef __felide_editor_qt5_qeditor_hpp__
#define __felide_editor_qt5_qeditor_hpp__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <felide/ProjectItem.hpp>
#include <felide/view/Editor.hpp>

namespace felide { namespace view { namespace qt5 {

    class TabbedEditor;
    class EditorImpl : public QWidget, public felide::view::Editor {
        Q_OBJECT

    signals:
        void titleUpdated(const EditorImpl *view);

    public:
        explicit EditorImpl(QWidget *parent, ProjectItemPtr m_item);
        ~EditorImpl();

        ProjectItem* getItem();

        const ProjectItem* getItem() const;

        void setTabbedEditor(TabbedEditor *m_tabbedEditor);

    public:
        void setFocus();
        
    public:
        virtual void setText(const std::string &text) override;
        virtual std::string getText() const override;

        virtual void setSavePoint() override;
        virtual void emptyUndoBuffer() override;
        virtual void clearAll() override;
        virtual void setTabWidth(const int spaces) override;

        virtual void setFont(const std::string &name, const int size) override;

        virtual void setLexer(const Lexer &lexer) override {}
        
        virtual ProjectItem* getProjectItem() override;
        virtual const ProjectItem* getProjectItem() const override;

		virtual void setTitle(const std::string &title);

        virtual void undo() override;
        virtual void redo() override;

        virtual void cut() override;
        virtual void copy() override;
        virtual void paste() override;

    private:
        ProjectItemPtr m_item = nullptr;
        QsciScintilla *m_scintilla = nullptr;
        TabbedEditor *m_tabbedEditor = nullptr;
    };

    inline ProjectItem* EditorImpl::getItem() {
        return this->m_item.get();
    }

    inline const ProjectItem* EditorImpl::getItem() const {
        return this->m_item.get();
    }

    inline void EditorImpl::setTabbedEditor(TabbedEditor *tabbedEditor) {
        this->m_tabbedEditor = tabbedEditor;
    }
}}}

#endif // __felide_editor_hpp__
