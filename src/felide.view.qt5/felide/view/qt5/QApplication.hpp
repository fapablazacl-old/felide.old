
#ifndef __felide_editor_qt5_qapplication_hpp__
#define __felide_editor_qt5_qapplication_hpp__

#include <felide/Application.hpp>
#include "QDialogFactory.hpp"

namespace felide { namespace editor { namespace qt5 {

    class QApplication : public felide::editor::Application {
    public:
        QApplication();
    
        virtual void initialize(int argc, char **argv);
        virtual int execute(int argc, char **argv);
        
    private:
        QDialogFactory dialogFactory;
    };
}}}

#endif  // __felide_editor_qt5_application_hpp__
