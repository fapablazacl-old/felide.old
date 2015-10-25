
#ifndef __felide_editor_qt5_qtabbededitor_hpp__
#define __felide_editor_qt5_qtabbededitor_hpp__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <felide/ProjectItem.hpp>

#include "QEditor.hpp"

namespace felide { namespace editor { namespace qt5 {

    class QTabbedEditor : public QWidget {
        Q_OBJECT

    public:
        explicit QTabbedEditor(QWidget *parent);

        QEditor* openEditor(ProjectItemPtr item);
        QEditor* openEditor(ProjectItemPtr item, const QString &title);

        void closeEditor(const QEditor *editor);

        QEditor* getCurrentEditor();
        const QEditor* getCurrentEditor() const;

        const int getEditorCount() const;
        
        Editor* getEditor(const int index);
        
        const Editor* getEditor(const int index) const;
        
        void setEditorTitle(Editor *editor, const QString &title);
        
    public slots:
        void editorTitledChanged(const QEditor* editor);

    private:
        int getEditorIndex(const QEditor* editor) const;

    private:
        QTabWidget *tabWidget = nullptr;
    };
    
}}}

#endif // __felide_qt5_tabbededitor_hpp__
