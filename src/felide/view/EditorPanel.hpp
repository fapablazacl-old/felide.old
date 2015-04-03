
#ifndef __FELIDE_VIEW_EDITORPANEL_HPP__
#define __FELIDE_VIEW_EDITORPANEL_HPP__

#include <QWidget>
#include <QTabWidget>
#include <QWidgetList>

#include <felide/view/Editor.hpp>

namespace felide { namespace view {

    class EditorPanel : public QWidget {
        Q_OBJECT
        
    signals:
        void editorChanged();
        
        void editorClosed(Editor *editor);
        
    public:
        EditorPanel(QWidget *parent);
        
        void openEditor(Editor *editor);
        
        void closeEditor(Editor *editor);
        
        Editor* findNewEditor() const;
        
        void activateEditor(Editor *editor);
        
        Editor* getActiveEditor();
        const Editor* getActiveEditor() const;
        
    private:
        QTabWidget *tabWidget = nullptr;
    };
}}

#endif
