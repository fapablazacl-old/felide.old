
#ifndef __felide_qt5_tabbededitor_hpp__
#define __felide_qt5_tabbededitor_hpp__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <felide/ProjectItem.hpp>

#include "Editor.hpp"

namespace felide { namespace qt5 {
    class TabbedEditor : public QWidget {
        Q_OBJECT
        
    public:
        explicit TabbedEditor(QWidget *parent);
        
        void openEditor(ProjectItem *item);
        void openEditor(ProjectItem *item, const QString &title);
        
        void closeEditor(const Editor *editor);
        
        Editor* getCurrentEditor();
        const Editor* getCurrentEditor() const;
        
    public slots:
        void editorTitledChanged(const Editor* editor);
        
    private:
        int getEditorIndex(const Editor* editor) const;
        
    private:
        QTabWidget *tabWidget = nullptr;
    };
}}

#endif // __felide_qt5_tabbededitor_hpp__
