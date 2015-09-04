
#include "QMainWindow.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>

namespace felide { namespace qt5 {

    QMainWindow::QMainWindow() {
        this->ui = std::make_unique<Ui_MainWindow>();
        this->ui->setupUi(this);

        this->tabbedEditor = new QTabbedEditor(this);
        this->setCentralWidget(tabbedEditor);

        // file menu
        connect(this->ui->action_New, &QAction::triggered, this, &QMainWindow::handleFileNew);
        connect(this->ui->action_Open, &QAction::triggered, this, &QMainWindow::handleFileOpen);
        connect(this->ui->action_Save, &QAction::triggered, this, &QMainWindow::handleFileSave);
        connect(this->ui->actionSave_As, &QAction::triggered, this, &QMainWindow::handleFileSaveAs);
        connect(this->ui->actionClose, &QAction::triggered, this, &QMainWindow::handleFileClose);
        connect(this->ui->action_Exit, &QAction::triggered, this, &QMainWindow::handleFileExit);

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

    QMainWindow::~QMainWindow() {}

    void QMainWindow::handleFileNew() {
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

    void QMainWindow::handleFileOpen() {
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

    void QMainWindow::handleFileSave() {
        QEditor *editor = this->tabbedEditor->getCurrentEditor();

        if (!editor) {
            return;
        }

        if (!editor->getItem()->hasPath()) {
            this->handleFileSaveAs();
        } else {
            editor->save();
        }
    }

    void QMainWindow::handleFileSaveAs() {
        QEditor *editor = this->tabbedEditor->getCurrentEditor();

        if (!editor) {
            return;
        }

        QString path = QFileDialog::getSaveFileName(this, "Save File...", "", "(*.cpp)");

        editor->save(path);
    }

    void QMainWindow::handleFileClose() {
        const QEditor *editor = this->tabbedEditor->getCurrentEditor();
        this->tabbedEditor->closeEditor(editor);

        this->updateState();
    }

    void QMainWindow::handleFileExit() {
        this->close();
    }

    void QMainWindow::updateState() {
        const bool openedEditor = (this->tabbedEditor->getCurrentEditor()!=nullptr);

        this->ui->actionClose->setEnabled(openedEditor);
        this->ui->action_Undo->setEnabled(openedEditor);
        this->ui->action_Redo->setEnabled(openedEditor);
        this->ui->action_Cut->setEnabled(openedEditor);
        this->ui->actionC_opy->setEnabled(openedEditor);
        this->ui->action_Paste->setEnabled(openedEditor);
    }
}}
