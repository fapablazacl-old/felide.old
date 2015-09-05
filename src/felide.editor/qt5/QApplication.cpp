
#include "felide.editor/qt5/QApplication.hpp"
#include "felide.editor/qt5/QMainWindow.hpp"

namespace felide { namespace editor { namespace qt5 {
    int QApplication::execute(int argc, char **argv) {
        ::QApplication app(argc, argv);

        felide::qt5::QMainWindow mainWindow;

        mainWindow.show();

        return app.exec();
    }
}}}
