
#include "felide.editor/qt5/Application.hpp"
#include "felide.editor/qt5/MainWindow.hpp"

namespace felide { namespace editor { namespace qt5 {
    int Application::run(int argc, char **argv) {
        ::QApplication app(argc, argv);
        
        felide::qt5::MainWindow mainWindow;
        
        mainWindow.show();
        
        return app.exec();
    }
}}}
