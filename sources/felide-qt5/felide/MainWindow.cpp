
#include "MainWindow.hpp"

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "ProjectBrowser.hpp"

namespace felide {
    struct MainWindow::Private {
        QMenu *fileMenu = nullptr;
        QMenu *helpMenu = nullptr;

        ProjectBrowser *projectExplorer;

        void setupMenuBar(MainWindow *window) {
            window->setMenuBar(new QMenuBar());

            fileMenu = window->menuBar()->addMenu("&File");
            fileMenu->addAction("&Exit");
            
            helpMenu = window->menuBar()->addMenu("&Help");
            helpMenu->addAction("&About");
        }

        void setupCentralWidget(MainWindow *window) {
            projectExplorer = new ProjectBrowser(window);

            window->setCentralWidget(projectExplorer);
        }

        void setupUI(MainWindow *window) {
            this->setupCentralWidget(window);
            this->setupMenuBar(window);
        }
    };

    MainWindow::MainWindow() 
        : m_impl(new MainWindow::Private()) {

        m_impl->setupUI(this);
    }

    MainWindow::~MainWindow() {}
}

#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    felide::MainWindow window;

    window.show();

    return app.exec();
}
