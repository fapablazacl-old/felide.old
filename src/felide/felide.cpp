
#include <iostream>

#if defined(FELIDE_VIEW_QT5)
#include <felide/view/qt5/QApplication.hpp>
#endif 

#if defined(FELIDE_VIEW_WIN32)
#include <felide/view/win32/CApplication.hpp>
#endif 

int main(int argc, char **argv) {
    felide::editor::qt5::QApplication app;
    return app.run(argc, argv);
    
    return 0;
}
