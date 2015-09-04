
#ifndef __felide_qt5_tabbededitor_hpp__
#define __felide_qt5_tabbededitor_hpp__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <felide/ProjectItem.hpp>

#include "QEditor.hpp"

namespace felide { namespace qt5 {
    class QTabbedEditor : public QWidget {
        Q_OBJECT

    public:
        explicit QTabbedEditor(QWidget *parent);

        void openEditor(ProjectItem *item);
        void openEditor(ProjectItem *item, const QString &title);

        void closeEditor(const QEditor *editor);

        QEditor* getCurrentEditor();
        const QEditor* getCurrentEditor() const;

    public slots:
        void editorTitledChanged(const QEditor* editor);

    private:
        int getEditorIndex(const QEditor* editor) const;

    private:
        QTabWidget *tabWidget = nullptr;
    };
}}

#endif // __felide_qt5_tabbededitor_hpp__
