
#ifndef __felide_qt5_editor_hpp__
#define __felide_qt5_editor_hpp__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <felide/ProjectItem.hpp>

#include "felide.editor/Editor.hpp"

namespace felide { namespace qt5 {

    class QEditor : public QWidget, public felide::editor::Editor {
        Q_OBJECT

    signals:
        void titleUpdated(const QEditor *editor);

    public slots:
        void onUndo();
        void onRedo();

        void onCut();
        void onCopy();
        void onPaste();

    public:
        explicit QEditor(QWidget *parent, ProjectItemPtr item);
        ~QEditor();

        void open();
        void save();
        void save(QString path);

        ProjectItem* getItem();

        const ProjectItem* getItem() const;
        
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
        

    private:
        ProjectItemPtr item = nullptr;
        QsciScintilla *scintilla = nullptr;
    };

    inline ProjectItem* QEditor::getItem() {
        return this->item.get();
    }

    inline const ProjectItem* QEditor::getItem() const {
        return this->item.get();
    }
}}

#endif // __felide_editor_hpp__
