
#ifndef __felide_qt5_editor_hpp__
#define __felide_qt5_editor_hpp__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <felide/ProjectItem.hpp>

namespace felide { namespace qt5 {

    class QEditor : public QWidget {
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
        explicit QEditor(QWidget *parent, ProjectItem *item);
        ~QEditor();

        void open();
        void save();
        void save(QString path);

        ProjectItem* getItem();

        const ProjectItem* getItem() const;

    private:
        ProjectItem *item = nullptr;
        QsciScintilla *scintilla = nullptr;
    };

    inline ProjectItem* QEditor::getItem() {
        return this->item;
    }

    inline const ProjectItem* QEditor::getItem() const {
        return this->item;
    }
}}

#endif // __felide_editor_hpp__
