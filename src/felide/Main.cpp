
#include <QApplication>
#include <QWidget>
#include <felide/view/MainWindow.hpp>

int main(int argc, char **argv) 
{
    using felide::view::MainWindow;
    
    QApplication app(argc, argv);
    
    MainWindow window;
    window.resize(800, 500);
    window.move(300, 300);
    window.show();
    
    return app.exec();
}
