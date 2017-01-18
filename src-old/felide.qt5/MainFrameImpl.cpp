
#include "MainFrameImpl.hpp"

#include <iostream>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QDockWidget>

#include "AppImpl.hpp"
#include "WorkspaceView.hpp"

#include "felide.proj.cmake/WorkspaceCMake.hpp"

namespace felide { namespace view { namespace qt5 {

    MainFrameImpl::MainFrameImpl(AppImpl *appImpl) {
        m_appImpl = appImpl;

        this->loadDefaultWorkspace();
        
        // setup main control and child controls
        m_tabbedEditor = new TabbedEditor(this);
        this->setCentralWidget(m_tabbedEditor);

        this->setupMenus();        
        this->setupMenuHandlers();
        this->setupDockUI();
        
        // update menubar status
        this->updateEnableStatus();
    }
    
    void MainFrameImpl::setupMenus() {
        m_menuBar = new QMenuBar(this);
        
        /*
        struct MenuItem {
            QString title;
            QMenu *menu = nullptr;
            int identifier = -1;
            std::vector<MenuItem> childs;
            
            MenuItem(QMenu *menu_, const QString &title_, const std::vector<MenuItem> &childs_) : menu(menu_), title(title_), childs(childs_) {
            }
            
            MenuItem(int identifier_, const QString &title_) : identifier(identifier_), title(title_) {}
        };
        
        MenuItem items[] = {  
            {m_fileMenu, "&File", {
                {FileNew, "&New"},
                {MenuSeparator},
                {FileOpen, "&Open"},
                {MenuSeparator},
                {FileSave, "&Save"},
                {FileSaveAs, "&SaveAs"},                 
                {FileSaveAll, "&SaveAll"}, 
                {MenuSeparator},
                {FileClose, "&Close"},
                {MenuSeparator},
                {FileClose, "&Exit"}
            }}
        };
        */
        
        m_fileMenu = m_menuBar->addMenu("&File");
        m_editMenu = m_menuBar->addMenu("&Edit");
        m_viewMenu = m_menuBar->addMenu("&View");
        m_buildMenu = m_menuBar->addMenu("&Build");
        m_helpMenu = m_menuBar->addMenu("&Help");
        
        m_actions[FileNew] = m_fileMenu->addAction("&New");
        m_actions[FileOpen] = m_fileMenu->addAction("&Open");
        m_actions[FileSave] = m_fileMenu->addAction("&Save");
        m_actions[FileSaveAs] = m_fileMenu->addAction("Sa&ve As");
        m_actions[FileSaveAll] = m_fileMenu->addAction("Save &All");
        m_actions[FileClose] = m_fileMenu->addAction("&Close");
        m_actions[FileExit] = m_fileMenu->addAction("&Exit");
        
        m_actions[EditUndo] = m_editMenu->addAction("&Undo");
        m_actions[EditRedo] = m_editMenu->addAction("&Redo");
        m_actions[EditCut] = m_editMenu->addAction("&Cut");
        m_actions[EditCopy] = m_editMenu->addAction("C&opy");
        m_actions[EditPaste] = m_editMenu->addAction("&Paste");
        
        m_actions[ViewOutput] = m_viewMenu->addAction("&Output");
        m_actions[ViewWorkspace] = m_viewMenu->addAction("&Workspace");
        
        m_actions[BuildClean] = m_buildMenu->addAction("&Clean");
        m_actions[BuildExecute] = m_buildMenu->addAction("&Execute");
        
        m_actions[HelpAbout] = m_helpMenu->addAction("&About");
        
        this->setMenuBar(m_menuBar);
    }
    
    void MainFrameImpl::setupMenuHandlers() {
        
        // setup menu handlers
        connect(m_actions[FileNew], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileNew();
        });

        connect(m_actions[FileOpen], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileOpen();
        });

        connect(m_actions[FileSave], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSave();
        });

        connect(m_actions[FileSaveAs], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileSaveAs();
        });

        connect(m_actions[FileClose], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileClose();
        });

        connect(m_actions[FileExit], &QAction::triggered, this, [this]() {
            this->getHandler()->handleFileExit();
        });
        
        connect(m_actions[ViewWorkspace], &QAction::triggered, this, [this]() {
            if (m_workspaceDock->isVisible()) {
                m_workspaceDock->hide();
            } else {
                m_workspaceDock->show();
            }
        });
        
        connect(m_actions[ViewOutput], &QAction::triggered, this, [this]() {
            if (m_outputDock->isVisible()) {
                m_outputDock->hide();
            } else {
                m_outputDock->show();
            }
        });
    }
    
    void MainFrameImpl::setupDockUI() {
        // setup test dock widget
        m_workspaceDock = new QDockWidget("Workspace", this);
        
        m_workspaceView = new WorkspaceView(m_workspaceDock, m_workspace.get());
        
        m_workspaceDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        m_workspaceDock->setWidget(m_workspaceView);
        
        this->addDockWidget(Qt::LeftDockWidgetArea, m_workspaceDock);
        
        // setup output window
        m_outputDock = new QDockWidget("Output Window", this);
        
        m_outputTextEdit = new QPlainTextEdit(m_outputDock);
        // m_outputTextEdit
        
        m_outputDock->setAllowedAreas(Qt::BottomDockWidgetArea);
        m_outputDock->setWidget(m_outputTextEdit);
        
        this->addDockWidget(Qt::BottomDockWidgetArea, m_outputDock);        
    }
    
    void MainFrameImpl::updateEnableStatus() {
        const bool openedEditor = (this->getEditorCount() > 0);
        
        const int actions[] = {
            FileSave, FileSaveAs, FileSaveAll, FileClose, 
            EditUndo, EditRedo, EditCut, EditCopy, EditPaste
        };
        
        for (const int actionId : actions) {
            QAction *action = m_actions[actionId];
            
            if (action) {
                action->setEnabled(openedEditor);
            }
        }
    }
    
    void MainFrameImpl::loadDefaultWorkspace() {
        m_workspace = std::make_unique<felide::WorkspaceCMake>();
    }
    
    App* MainFrameImpl::getApp() {
        return m_appImpl;
    }
    
    const App* MainFrameImpl::getApp() const {
        return m_appImpl;
    }
}}}
