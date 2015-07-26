
#ifndef __felide_qt5_editor_hpp__
#define __felide_qt5_editor_hpp__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <felide/ProjectItem.hpp>

namespace felide { namespace qt5 {

    class Editor : public QWidget {
        Q_OBJECT
        
    public:
        explicit Editor(QWidget *parent, ProjectItem *item);
        ~Editor();
      
        ProjectItem* getItem();
        
        const ProjectItem* getItem() const;
        
    private:
        ProjectItem *item = nullptr;
        QsciScintilla *scintilla = nullptr;
    };
    
    inline ProjectItem* Editor::getItem() {
        return this->item;
    }
    
    inline const ProjectItem* Editor::getItem() const {
        return this->item;
    }
}}

#endif // __felide_editor_hpp__
