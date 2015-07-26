
#include <QApplication>
#include "qt5/MainWindow.hpp"

int main(int argc, char **argv) {
    ::QApplication app(argc, argv);
    
    felide::qt5::MainWindow mainWindow;
    
    mainWindow.show();
    
    return app.exec();
}
