
#include <felide/interface/MainWindow.hpp>
#include <QApplication>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    
    felide::gui::MainWindow mainWindow;
    mainWindow.setWindowTitle("Hello");
    mainWindow.setVisible(true);
    
    return app.exec();
}
