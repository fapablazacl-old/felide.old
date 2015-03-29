
#ifndef __FELIDE_VIEW_EDITORPANEL_HPP__
#define __FELIDE_VIEW_EDITORPANEL_HPP__

#include <QWidget>
#include <QTabWidget>

#include <felide/view/SourceEditor.hpp>

namespace felide { namespace view {

    class EditorPanel : public QWidget {
        Q_OBJECT
        
    public:
        EditorPanel(QWidget *parent);
        
        void openEditor(SourceEditor *editor);
        
        void closeEditor(SourceEditor *editor);
        
        SourceEditor* getActiveEditor();
        const SourceEditor* getActiveEditor() const;
        
    private:
        QTabWidget *tabWidget = nullptr;
    };
}}

#endif
