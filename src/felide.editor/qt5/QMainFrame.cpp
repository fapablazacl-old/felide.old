
#include "QMainFrame.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>

namespace felide { namespace qt5 {

    using namespace felide::editor;

    QMainFrame::QMainFrame(felide::editor::DialogFactory *factory) : MainFrame(factory) {
        this->ui = std::make_unique<Ui_MainWindow>();
        this->ui->setupUi(this);
        
        this->tabbedEditor = new QTabbedEditor(this);
        this->setCentralWidget(tabbedEditor);

        // file menu
        connect(this->ui->action_New, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileNew();
        });
        
        connect(this->ui->action_Open, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileOpen();
        });
        
        connect(this->ui->action_Save, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSave();
        });
        
        connect(this->ui->actionSave_As, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSaveAs();
        });
        
        connect(this->ui->actionClose, &QAction::triggered, this, [this]() {
            // this->getHandler()->handleFileClose();
        });
        
        connect(this->ui->action_Exit, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileExit();
        });
        
        this->updateState();
    }

    QMainFrame::~QMainFrame() {}

    void QMainFrame::close() {
        QMainWindow::close();
    }

    Editor* QMainFrame::createEditor(ProjectItemPtr item) {
        return nullptr;
    }

    Editor* QMainFrame::getCurrentEditor() {
        return this->tabbedEditor->getCurrentEditor();
    }
    
    const Editor* QMainFrame::getCurrentEditor() const {
        return this->tabbedEditor->getCurrentEditor();
    }

    /*
    void QMainFrame::handleFileNew() {
        // int untitledCount = this->untitledCount;
        // untitledCount ++;

        QString title = "";
        // title.sprintf("untitled%02d", untitledCount);

        auto projectItem = std::make_unique<ProjectItem>();
        this->tabbedEditor->openEditor(std::move(projectItem), title);
        
        // this->items.push_back(std::move(projectItem));
        // this->untitledCount = untitledCount;

        this->updateState();
    }

    void QMainFrame::handleFileOpen() {
        QString path = QFileDialog::getOpenFileName(this, "Open File...", "", "(*.cpp)");

        if (path.isEmpty()) {
            return;
        }

        auto projectItem = std::make_unique<ProjectItem>(path.toStdString());

        QString title = QString::fromStdString(projectItem->getName());
        this->tabbedEditor->openEditor(projectItem.get(), title);

        // this->items.push_back(std::move(projectItem));

        this->updateState();
    }

    void QMainFrame::handleFileSave() {
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

    void QMainFrame::handleFileSaveAs() {
        QEditor *editor = this->tabbedEditor->getCurrentEditor();

        if (!editor) {
            return;
        }

        QString path = QFileDialog::getSaveFileName(this, "Save File...", "", "(*.cpp)");

        editor->save(path);
    }

    void QMainFrame::handleFileClose() {
        const QEditor *editor = this->tabbedEditor->getCurrentEditor();
        this->tabbedEditor->closeEditor(editor);

        this->updateState();
    }

    void QMainFrame::handleFileExit() {
        this->close();
    }
    */

    void QMainFrame::updateState() {
        const bool openedEditor = (this->tabbedEditor->getCurrentEditor()!=nullptr);

        this->ui->actionClose->setEnabled(openedEditor);
        this->ui->action_Undo->setEnabled(openedEditor);
        this->ui->action_Redo->setEnabled(openedEditor);
        this->ui->action_Cut->setEnabled(openedEditor);
        this->ui->actionC_opy->setEnabled(openedEditor);
        this->ui->action_Paste->setEnabled(openedEditor);
    }
}}
