
#include "QtApplication.hpp"
#include <QApplication>

#include "MainWindow.hpp"

namespace felide {
    int QtApplication::run(int argc, char **argv) {
        QApplication app(argc, argv);

        MainWindow window;

        window.show();

        return app.exec();
    }
}

int main(int argc, char **argv) {
    felide::QtApplication app;

    return app.run(argc, argv);
}
