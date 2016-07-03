
#include "MainFrameImpl.hpp"

#include <iostream>
#include <QAction>
#include <QFileDialog>
#include <QDockWidget>

#include "AppImpl.hpp"

namespace felide { namespace view { namespace qt5 {

    MainFrameImpl::MainFrameImpl(AppImpl *appImpl) {
        m_appImpl = appImpl;
        
        m_ui = std::make_unique<Ui_MainWindow>();
        m_ui->setupUi(this);

        // setup main control
        m_tabbedEditor = new TabbedEditor(this);
        this->setCentralWidget(m_tabbedEditor);
        
        // setup dock windows
//        auto *dock = new QDockWidget("Test01", this);
//        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//        dock->setWidget(new QTextEdit("This is a test text", dock));
//
//        this->addDockWidget(Qt::LeftDockWidgetArea, dock);
        
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
    
    App* MainFrameImpl::getApp() {
        return m_appImpl;
    }
    
    const App* MainFrameImpl::getApp() const {
        return m_appImpl;
    }
}}}
