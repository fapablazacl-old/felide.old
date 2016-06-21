
#include "QApplication.hpp"
#include "QMainFrame.hpp"

#include <QDockWidget>

namespace felide { namespace view { namespace qt5 {

    int QApplication::run(int argc, char **argv) {
        ::QApplication app(argc, argv);
        
        QMainFrame mainFrame(&this->dialogFactory);
        mainFrame.show();

        return app.exec();    
    }
}}}
