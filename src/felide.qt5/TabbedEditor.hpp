
#ifndef __felide_editor_qt5_qtabbededitor_hpp__
#define __felide_editor_qt5_qtabbededitor_hpp__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <felide/ProjectItem.hpp>

#include "EditorImpl.hpp"

namespace felide { namespace view { namespace qt5 {

    class TabbedEditor : public QWidget {
        Q_OBJECT

    public:
        explicit TabbedEditor(QWidget *parent);

        EditorImpl* openEditor(ProjectItemPtr item);
        EditorImpl* openEditor(ProjectItemPtr item, const QString &title);

        void closeEditor(const EditorImpl *view);

        EditorImpl* getCurrentEditor();
        const EditorImpl* getCurrentEditor() const;

        const int getEditorCount() const;
        
        Editor* getEditor(const int index);
        
        const Editor* getEditor(const int index) const;
        
        void setEditorTitle(Editor *view, const QString &title);
        
    public slots:
        void editorTitledChanged(const EditorImpl* view);

    private:
        int getEditorIndex(const EditorImpl* view) const;

    private:
        QTabWidget *m_tabWidget = nullptr;
    };
    
}}}

#endif // __felide_qt5_tabbededitor_hpp__
