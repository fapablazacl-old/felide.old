
#ifndef __felide_editor_qt5_qapplication_hpp__
#define __felide_editor_qt5_qapplication_hpp__

#include "felide/App.hpp"
#include "QDialogFactory.hpp"

namespace felide { namespace view { namespace qt5 {
    class QApplication : public App {
    public:
        virtual int run(int argc, char **argv);
        
    private:
        QDialogFactory dialogFactory;
    };
}}}

#endif  // __felide_editor_qt5_application_hpp__
