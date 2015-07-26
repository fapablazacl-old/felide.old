
#include "MainWindow.hpp"

namespace felide { namespace qt5 {

    MainWindow::MainWindow() {
        this->ui = std::make_unique<Ui_MainWindow>();
        this->ui->setupUi(this);
        
        this->tabbedEditor = new TabbedEditor(this);
        this->setCentralWidget(tabbedEditor);
        
        auto projectItem = std::make_unique<ProjectItem>();
        
        this->tabbedEditor->openEditor(projectItem.get());
        this->items.push_back(std::move(projectItem));
    }

    MainWindow::~MainWindow() {
        
    }
}}
