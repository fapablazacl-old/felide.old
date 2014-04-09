
#include <QApplication> 
#include <felide/interface/MainWindow.hpp>

int main(int argc, char* argv[]) {
    using namespace felide;
    using namespace felide::interface;
    
    QApplication app(argc, argv);
    
    MainWindow *window = new MainWindow(nullptr);
    window->show();

    return app.exec();
}
