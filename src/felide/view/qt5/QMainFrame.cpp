
#include "QMainFrame.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>
#include <QDockWidget>

namespace felide { namespace view { namespace qt5 {

    using namespace felide::view;

    QMainFrame::QMainFrame(felide::view::DialogFactory *factory) : MainFrame(factory) {
        this->ui = std::make_unique<Ui_MainWindow>();
        this->ui->setupUi(this);

        // setup main control
        this->tabbedEditor = new QTabbedEditor(this);
        this->setCentralWidget(tabbedEditor);
        
        // setup dock windows
        auto *dock = new QDockWidget("Test01", this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        dock->setWidget(new QTextEdit("This is a test text", dock));
        
        this->addDockWidget(Qt::LeftDockWidgetArea, dock);
        
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
            this->getHandler()->handleFileClose();
        });

        connect(this->ui->action_Exit, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileExit();
        });
        
        // update menubar status
        this->updateEnableStatus();
    }

    QMainFrame::~QMainFrame() {}

    void QMainFrame::close() {
        QMainWindow::close();
    }

    Editor* QMainFrame::createEditor(ProjectItemPtr item) {
    	return this->tabbedEditor->openEditor(std::move(item));
    }

    void QMainFrame::closeEditor(Editor* view) {
        this->tabbedEditor->closeEditor(static_cast<QEditor*>(view));
    }

    Editor* QMainFrame::getCurrentEditor() {
        return this->tabbedEditor->getCurrentEditor();
    }

    const Editor* QMainFrame::getCurrentEditor() const {
        return this->tabbedEditor->getCurrentEditor();
    }

    void QMainFrame::updateEnableStatus() {
        const bool openedEditor = (this->getEditorCount() > 0);

        this->ui->action_Save->setEnabled(openedEditor);
        this->ui->actionSave_As->setEnabled(openedEditor);
        this->ui->actionSaveAll->setEnabled(openedEditor);
        this->ui->actionClose->setEnabled(openedEditor);
        this->ui->action_Undo->setEnabled(openedEditor);
        this->ui->action_Redo->setEnabled(openedEditor);
        this->ui->action_Cut->setEnabled(openedEditor);
        this->ui->actionC_opy->setEnabled(openedEditor);
        this->ui->action_Paste->setEnabled(openedEditor);
    }

    int QMainFrame::getEditorCount() const {
        return this->tabbedEditor->getEditorCount();
    }

    Editor* QMainFrame::getEditor(const int index) {
        return this->tabbedEditor->getEditor(index);
    }

    const Editor* QMainFrame::getEditor(const int index) const {
        return this->tabbedEditor->getEditor(index);
    }
    
    void QMainFrame::setEditorTitle(Editor *view, const std::string &title)  {
        
    }
    
    std::string QMainFrame::getEditorTitle(Editor *view) const {
        return "";
    }
}}}
