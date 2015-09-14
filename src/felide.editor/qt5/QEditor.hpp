
#ifndef __felide_editor_qt5_qeditor_hpp__
#define __felide_editor_qt5_qeditor_hpp__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <felide/ProjectItem.hpp>

#include "felide.editor/Editor.hpp"

namespace felide { namespace editor { namespace qt5 {

    class QTabbedEditor;
    class QEditor : public QWidget, public felide::editor::Editor {
        Q_OBJECT

    signals:
        void titleUpdated(const QEditor *editor);

    public:
        explicit QEditor(QWidget *parent, ProjectItemPtr item);
        ~QEditor();

        ProjectItem* getItem();

        const ProjectItem* getItem() const;

        void setTabbedEditor(QTabbedEditor *tabbedEditor);

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

        virtual ProjectItem* getProjectItem() override;
        virtual const ProjectItem* getProjectItem() const override;

		virtual void setTitle(const std::string &title) override;

        virtual void undo() override;
        virtual void redo() override;

        virtual void cut() override;
        virtual void copy() override;
        virtual void paste() override;

    private:
        ProjectItemPtr item = nullptr;
        QsciScintilla *scintilla = nullptr;
        QTabbedEditor *tabbedEditor = nullptr;
    };

    inline ProjectItem* QEditor::getItem() {
        return this->item.get();
    }

    inline const ProjectItem* QEditor::getItem() const {
        return this->item.get();
    }

    inline void QEditor::setTabbedEditor(QTabbedEditor *tabbedEditor) {
        this->tabbedEditor = tabbedEditor;
    }
}}}

#endif // __felide_editor_hpp__
