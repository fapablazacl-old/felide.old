
#include <QApplication>
#include <felide/view/MainWindow.hpp>

int main(int argc, char **argv) 
{
    QApplication app(argc, argv);
    
    felide::view::MainWindow window;
    
    window.resize(800, 500);
    window.move(300, 300);
    window.show();
    
    return app.exec();
}
