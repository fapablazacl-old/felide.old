
#include "MainWindow.hpp"

#include <map>
#include <cassert>
#include <iostream>
#include <functional>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>
#include <QDesktopWidget>
#include <QFileDialog>

#include "ProjectBrowser.hpp"
#include "DocumentManager.hpp"

namespace felide {

    struct Menu;

    struct MenuBar {
        explicit MenuBar(const std::initializer_list<Menu> menues_) 
            : menues(menues_) {}

        std::vector<Menu> menues;
    };

    struct Menu {
        std::string key;
        bool separator = false;
        std::vector<Menu> childs;

        Menu() {}

        Menu(const std::string &key_, const std::vector<Menu> &childs_)
            : key(key_), childs(childs_) {}

        static Menu Item(const std::string &key) {
            Menu menu;

            menu.key = key;

            return menu;
        }

        static Menu Separator() {
            Menu menu;

            menu.separator = true;

            return menu;
        }
    };
    
    std::map<std::string, std::string> strings = {
        {"file", "&File"}, 
        {"file.openfolder", "&Open Folder"}, 
        {"file.save", "&Save"}, 
        {"file.saveall", "Save &All"}, 
        {"file.exit", "&Exit"}, 
        {"edit", "&Edit"}, 
        {"edit.undo", "&Undo"}, 
        {"edit.redo", "&Redo"}, 
        {"edit.cut", "&Cut"}, 
        {"edit.copy", "&Copy"}, 
        {"edit.paste", "&Paste"}, 
        {"help", "&Help"},
        {"help.about", "&About"}
    };

    MenuBar menuBar {
        Menu("file", {
            Menu::Item("file.openfolder"), 
            Menu::Separator(), 
            Menu::Item("file.save"), 
            Menu::Item("file.saveall"), 
            Menu::Separator(), 
            Menu::Item("file.exit")
        }), 

        Menu("edit", {
            Menu::Item("edit.undo"), 
            Menu::Item("edit.redo"), 
            Menu::Separator(), 
            Menu::Item("edit.cut"), 
            Menu::Item("edit.copy"), 
            Menu::Item("edit.paste")
        }),

        Menu("help", {
            Menu::Item("help.about")
        })
    };


    struct MainWindow::Private {
        std::map<std::string, QAction*> actions;
        std::map<std::string, std::string> strings;

        std::map<std::string, std::function<void()>> functions;

        ProjectBrowser *projectExplorer = nullptr;
        DocumentManager *documentManager = nullptr;

        Private() {
            // inicializar las cadenas
            strings = felide::strings;

            functions = {
                {"file.openfolder", std::bind(&MainWindow::Private::onOpenFolder, this)}
            };
        }

        QMenu* generateMenu(const Menu &menu) {
            auto result = new QMenu(strings[menu.key].c_str());

            for (const Menu &child : menu.childs) {
                if (child.separator == true) {
                    result->addSeparator();

                } else if (child.childs.size() > 0) {
                    result->addMenu(this->generateMenu(child));

                } else {
                    const std::string key = child.key;

                    QAction *action = result->addAction(strings[key].c_str());

                    actions[key] = action;
                }
            }

            return result;
        }

        QMenuBar* generateMenuBar(const MenuBar &menuBar) {
            auto result = new QMenuBar();

            for (const Menu &menu : menuBar.menues) {
                result->addMenu(this->generateMenu(menu));
            }

            return result;
        }

        void setupMenuBar(MainWindow *window) {
            window->setMenuBar(this->generateMenuBar(felide::menuBar));
        }

        void setupWidgets(MainWindow *window) {
            auto dock = new QDockWidget("Project Explorer", window);

            projectExplorer = new ProjectBrowser(dock);

            dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
            dock->setWidget(projectExplorer);

            window->addDockWidget(Qt::LeftDockWidgetArea, dock);

            documentManager = new DocumentManager(window);
            window->setCentralWidget(documentManager);
        }

        void setupUI(MainWindow *window) {
            assert(window);

            this->setupMenuBar(window);
            this->setupWidgets(window);

            QDesktopWidget desktopWidget;

            const QRect screenSize = desktopWidget.availableGeometry(desktopWidget.primaryScreen());

            window->setMinimumSize(screenSize.size() * 0.4);
            window->resize(screenSize.size() * 0.7);
        }

        void connectSignals() {
            for (const auto &pair : actions) {
                auto functionPos = functions.find(pair.first);

                if (functionPos == functions.end()) {
                    continue;
                }

                QAction *action = pair.second;

                QObject::connect(action, &QAction::triggered, functionPos->second);
            }
        }

        void onOpenFolder() {
            QFileDialog dialog;
            
            dialog.setFileMode(QFileDialog::Directory);
            dialog.setOption(QFileDialog::ShowDirsOnly);

            if (dialog.exec()) {
                const QStringList folders = dialog.selectedFiles();

                assert(folders.size() == 1);

                const QString folder = folders[0];

                projectExplorer->setProjectFolder(folder);
            }
        }
    };

    MainWindow::MainWindow() 
        : m_impl(new MainWindow::Private()) {

        m_impl->setupUI(this);
        m_impl->connectSignals();
    }
    
    MainWindow::~MainWindow() {}
}
