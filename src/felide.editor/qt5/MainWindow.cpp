
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
        
        // file menu
        connect(this->ui->action_New, &QAction::triggered, this, &MainWindow::handleFileNew);
        connect(this->ui->action_Open, &QAction::triggered, this, &MainWindow::handleFileOpen);
        connect(this->ui->action_Save, &QAction::triggered, this, &MainWindow::handleFileSave);
        connect(this->ui->actionSave_As, &QAction::triggered, this, &MainWindow::handleFileSaveAs);
        connect(this->ui->actionClose, &QAction::triggered, this, &MainWindow::handleFileClose);
        connect(this->ui->action_Exit, &QAction::triggered, this, &MainWindow::handleFileExit);
        
        // edit menu
        connect(this->ui->action_Undo, &QAction::triggered, [this]() {
            this->tabbedEditor->getCurrentEditor()->onUndo();
        });
        
        connect(this->ui->action_Redo, &QAction::triggered, [this]() {
            this->tabbedEditor->getCurrentEditor()->onRedo();
        });
        
        connect(this->ui->action_Cut, &QAction::triggered, [this]() {
            this->tabbedEditor->getCurrentEditor()->onCut();
        });
        
        connect(this->ui->actionC_opy, &QAction::triggered, [this]() {
            this->tabbedEditor->getCurrentEditor()->onCopy();
        });
        
        connect(this->ui->action_Paste, &QAction::triggered, [this]() {
            this->tabbedEditor->getCurrentEditor()->onPaste();
        });
        
        this->updateState();
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
        
        this->updateState();
    }
    
    void MainWindow::handleFileOpen() {
        QString path = QFileDialog::getOpenFileName(this, "Open File...", "", "(*.cpp)");
        
        if (path.isEmpty()) {
            return;
        }
        
        auto projectItem = std::make_unique<ProjectItem>(path.toStdString());
        
        QString title = QString::fromStdString(projectItem->getName());
        this->tabbedEditor->openEditor(projectItem.get(), title);
        
        this->items.push_back(std::move(projectItem));
        
        this->updateState();
    }

    void MainWindow::handleFileSave() {
        Editor *editor = this->tabbedEditor->getCurrentEditor();
        
        if (!editor) {
            return;
        }
        
        if (!editor->getItem()->hasPath()) {
            this->handleFileSaveAs();
        } else {
            editor->save();
        }
    }

    void MainWindow::handleFileSaveAs() {
        Editor *editor = this->tabbedEditor->getCurrentEditor();
        
        if (!editor) {
            return;
        }
        
        QString path = QFileDialog::getSaveFileName(this, "Save File...", "", "(*.cpp)");
        
        editor->save(path);
    }

    void MainWindow::handleFileClose() {
        const Editor *editor = this->tabbedEditor->getCurrentEditor();
        this->tabbedEditor->closeEditor(editor);
        
        this->updateState();
    }

    void MainWindow::handleFileExit() {
        this->close();
    }
    
    void MainWindow::updateState() {
        const bool openedEditor = (this->tabbedEditor->getCurrentEditor()!=nullptr);

        this->ui->actionClose->setEnabled(openedEditor);
        this->ui->action_Undo->setEnabled(openedEditor);
        this->ui->action_Redo->setEnabled(openedEditor);
        this->ui->action_Cut->setEnabled(openedEditor);
        this->ui->actionC_opy->setEnabled(openedEditor);
        this->ui->action_Paste->setEnabled(openedEditor);
    }
}}
