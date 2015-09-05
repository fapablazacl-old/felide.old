
#include "felide.editor/qt5/QApplication.hpp"
#include "felide.editor/qt5/QMainFrame.hpp"

namespace felide { namespace editor { namespace qt5 {
    
    QApplication::QApplication() {}
    
    void QApplication::initialize(int argc, char **argv) {
        Application::initialize(argc, argv);
    }
    
    int QApplication::execute(int argc, char **argv) {
        ::QApplication app(argc, argv);

        felide::qt5::QMainFrame mainFrame(&this->dialogFactory);

        mainFrame.show();

        return app.exec();
    }
}}}
