
#ifndef __felide_qt5_tabbededitor_hpp__
#define __felide_qt5_tabbededitor_hpp__

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <felide/ProjectItem.hpp>

namespace felide { namespace qt5 {
    class TabbedEditor : public QWidget {
        Q_OBJECT
        
    public:
        explicit TabbedEditor(QWidget *parent);
        
        void openEditor(ProjectItem *item);
        void openEditor(ProjectItem *item, const QString &title);
        
    private:
        QTabWidget *tabWidget = nullptr;
    };
}}

#endif // __felide_qt5_tabbededitor_hpp__
