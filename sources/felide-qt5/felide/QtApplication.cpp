
#include "QtApplication.hpp"
#include <QApplication>

#include "MainWindow.hpp"

#include "felide/Menu.hpp"
#include "felide/Resource.hpp"
#include "felide/ResourceManager.hpp"

namespace felide {
    int QtApplication::run(int argc, char **argv) {
        QApplication app(argc, argv);

        auto menuBarResource = this->getResourceManager()->getResource<ResourceWrapper<MenuBar>>("menuBar");
        auto menuBar = menuBarResource->get();

        auto stringResource = this->getResourceManager()->getResource<StringResource>("strings");

        MainWindow window(menuBar, stringResource);

        window.show();

        return app.exec();
    }
}

int main(int argc, char **argv) {
    felide::QtApplication app;

    return app.run(argc, argv);
}
