
#include "QMainFrame.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>

namespace felide { namespace editor { namespace qt5 {

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
            this->getHandler()->handleFileClose();
        });

        connect(this->ui->action_Exit, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileExit();
        });

        this->updateEnableStatus();
    }

    QMainFrame::~QMainFrame() {}

    void QMainFrame::close() {
        QMainWindow::close();
    }

    Editor* QMainFrame::createEditor(ProjectItemPtr item) {
    	return this->tabbedEditor->openEditor(std::move(item));
    }

    void QMainFrame::closeEditor(Editor* editor) {
        this->tabbedEditor->closeEditor(static_cast<QEditor*>(editor));
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
    
    void QMainFrame::setEditorTitle(Editor *editor, const std::string &title)  {
    
    }
    
    std::string QMainFrame::getEditorTitle(Editor *editor) const {
        return "";
    }
}}}
