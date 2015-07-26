
#include "MainWindow.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>

namespace felide { namespace qt5 {

    MainWindow::MainWindow() {
        this->ui = std::make_unique<Ui_MainWindow>();
        this->ui->setupUi(this);
        
        this->tabbedEditor = new TabbedEditor(this);
        this->setCentralWidget(tabbedEditor);
        
        // connect signals
        connect(this->ui->action_New, &QAction::triggered, this, &MainWindow::handleFileNew);
        connect(this->ui->action_Open, &QAction::triggered, this, &MainWindow::handleFileOpen);
        connect(this->ui->action_Save, &QAction::triggered, this, &MainWindow::handleFileSave);
        connect(this->ui->actionSave_As, &QAction::triggered, this, &MainWindow::handleFileSaveAs);
        connect(this->ui->actionClose, &QAction::triggered, this, &MainWindow::handleFileClose);
        connect(this->ui->action_Exit, &QAction::triggered, this, &MainWindow::handleFileExit);
    }
    
    MainWindow::~MainWindow() {}

    void MainWindow::handleFileNew() {
        int untitledCount = this->untitledCount;
        
        untitledCount ++;
        
        QString title = "";
        title.sprintf("untitled%02d", untitledCount);
        
        auto projectItem = std::make_unique<ProjectItem>();
        this->tabbedEditor->openEditor(projectItem.get(), title);
        this->items.push_back(std::move(projectItem));
        
        this->untitledCount = untitledCount;
    }
    
    void MainWindow::handleFileOpen() {
        QString path = QFileDialog::getOpenFileName(this, "Open Source ...", "", "(*.cpp)");
        auto item = std::make_unique<ProjectItem>(path.toStdString());
        
        QString title = QString::fromStdString(item->getName());
        this->tabbedEditor->openEditor(item.get(), title);
    }

    void MainWindow::handleFileSave() {
        
    }

    void MainWindow::handleFileSaveAs() {
        
    }

    void MainWindow::handleFileClose() {
        
    }

    void MainWindow::handleFileExit() {
        this->close();
    }
}}
