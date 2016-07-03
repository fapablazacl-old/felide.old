
#include "MainFrameImpl.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>
#include <QDockWidget>

namespace felide { namespace view { namespace qt5 {

    using namespace felide::view;

    MainFrameImpl::MainFrameImpl(felide::view::DialogFactory *factory) : MainFrame(factory) {
        m_ui = std::make_unique<Ui_MainWindow>();
        m_ui->setupUi(this);

        // setup main control
        m_tabbedEditor = new TabbedEditor(this);
        this->setCentralWidget(m_tabbedEditor);
        
        // setup dock windows
        auto *dock = new QDockWidget("Test01", this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        dock->setWidget(new QTextEdit("This is a test text", dock));
        
        this->addDockWidget(Qt::LeftDockWidgetArea, dock);
        
        connect(m_ui->action_New, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileNew();
        });

        connect(m_ui->action_Open, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileOpen();
        });

        connect(m_ui->action_Save, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSave();
        });

        connect(m_ui->actionSave_As, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSaveAs();
        });

        connect(m_ui->actionClose, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileClose();
        });

        connect(m_ui->action_Exit, &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileExit();
        });
        
        // update menubar status
        this->updateEnableStatus();
    }

    MainFrameImpl::~MainFrameImpl() {}

    void MainFrameImpl::close() {
        QMainWindow::close();
    }

    Editor* MainFrameImpl::createEditor(ProjectItemPtr item) {
    	return m_tabbedEditor->openEditor(std::move(item));
    }

    void MainFrameImpl::closeEditor(Editor* view) {
        m_tabbedEditor->closeEditor(static_cast<EditorImpl*>(view));
    }

    Editor* MainFrameImpl::getCurrentEditor() {
        return m_tabbedEditor->getCurrentEditor();
    }

    const Editor* MainFrameImpl::getCurrentEditor() const {
        return m_tabbedEditor->getCurrentEditor();
    }

    void MainFrameImpl::updateEnableStatus() {
        const bool openedEditor = (this->getEditorCount() > 0);

        m_ui->action_Save->setEnabled(openedEditor);
        m_ui->actionSave_As->setEnabled(openedEditor);
        m_ui->actionSaveAll->setEnabled(openedEditor);
        m_ui->actionClose->setEnabled(openedEditor);
        m_ui->action_Undo->setEnabled(openedEditor);
        m_ui->action_Redo->setEnabled(openedEditor);
        m_ui->action_Cut->setEnabled(openedEditor);
        m_ui->actionC_opy->setEnabled(openedEditor);
        m_ui->action_Paste->setEnabled(openedEditor);
    }

    int MainFrameImpl::getEditorCount() const {
        return m_tabbedEditor->getEditorCount();
    }

    Editor* MainFrameImpl::getEditor(const int index) {
        return m_tabbedEditor->getEditor(index);
    }

    const Editor* MainFrameImpl::getEditor(const int index) const {
        return m_tabbedEditor->getEditor(index);
    }
    
    void MainFrameImpl::setEditorTitle(Editor *view, const std::string &title)  {
        
    }
    
    std::string MainFrameImpl::getEditorTitle(Editor *view) const {
        return "";
    }
}}}
