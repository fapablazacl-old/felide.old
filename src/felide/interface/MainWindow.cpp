/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

//    piemioteadoroooo

#include <QMenuBar>

#include <iostream>
#include <boost/make_shared.hpp>

#include <felide/interface/MainWindow.hpp>
#include <felide/interface/EditorWidgetManager.hpp>

namespace felide { namespace interface {
    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
        this->setupUi();
        this->connectSignals();
        
        this->workspace = boost::make_shared<felide::projects::Workspace>();
    }
    
    void MainWindow::setupUi() {
        this->fileMenu = this->menuBar()->addMenu("&File");
        this->editMenu = this->menuBar()->addMenu("&Edit");
        this->viewMenu = this->menuBar()->addMenu("&View");
        this->projectMenu = this->menuBar()->addMenu("&Project");
        this->buildMenu = this->menuBar()->addMenu("&Build");
        this->debugMenu = this->menuBar()->addMenu("&Debug");
        this->toolsMenu = this->menuBar()->addMenu("&Tools");
        this->helpMenu = this->menuBar()->addMenu("&Help");
        
        this->fileNewAction = new QAction("&New ...", this);
        this->fileOpenAction = new QAction("&Open ...", this);
        this->fileSaveAction = new QAction("&Save ...", this);
        this->fileSaveAllAction = new QAction("Save &All...", this);
        this->fileCloseAction = new QAction("&Close", this);
        this->filePrintAction = new QAction("&Print", this);
        this->fileExitAction = new QAction("&Exit", this);
        
        this->fileMenu->addAction(this->fileNewAction);
        this->fileMenu->addSeparator();
        this->fileMenu->addAction(this->fileOpenAction);
        this->fileMenu->addAction(this->fileSaveAction);
        this->fileMenu->addAction(this->fileSaveAllAction);
        this->fileMenu->addSeparator();
        this->fileMenu->addAction(this->fileCloseAction);
        this->fileMenu->addSeparator();
        this->fileMenu->addAction(this->filePrintAction);
        this->fileMenu->addSeparator();
        this->fileMenu->addAction(this->fileExitAction);
        
        this->editUndoAction = new QAction("&Undo", this);
        this->editRedoAction = new QAction("&Redo", this);
        this->editCutAction = new QAction("&Cut", this);
        this->editCopyAction = new QAction("C&opy", this);
        this->editPasteAction = new QAction("&Paste", this);
        this->editDeleteAction = new QAction("&Delete", this);
        this->editSelectAllAction = new QAction("Select &All", this);
        
        this->editMenu->addAction(this->editUndoAction);
        this->editMenu->addAction(this->editRedoAction);
        this->editMenu->addSeparator();
        this->editMenu->addAction(this->editCutAction);
        this->editMenu->addAction(this->editCopyAction);
        this->editMenu->addAction(this->editPasteAction);
        this->editMenu->addAction(this->editDeleteAction);
        this->editMenu->addSeparator();
        this->editMenu->addAction(this->editSelectAllAction);
        
        
        this->viewProjectViewAction = new QAction("&Project View Window", this);
        this->viewClassViewAction = new QAction("&Class View Window", this);
        this->viewOutputWindowAction = new QAction("&Output Window", this);
        this->viewErrorListWindowAction = new QAction("&Error List Window", this);
        
        this->viewMenu->addAction(this->viewProjectViewAction);
        this->viewMenu->addAction(this->viewClassViewAction);
        this->viewMenu->addAction(this->viewOutputWindowAction);
        this->viewMenu->addAction(this->viewErrorListWindowAction);
       
        
        this->projectAddItemAction = new QAction("&Add Item ...", this);
        this->projectEditItemAction = new QAction("&Edit Item", this);
        this->projectRemoveItemAction = new QAction("&Remove Item", this);
        this->projectDeleteItemAction = new QAction("&Delete Item", this);
                
        this->projectMenu->addAction(this->projectAddItemAction);
        this->projectMenu->addSeparator();
        this->projectMenu->addAction(this->projectEditItemAction);
        this->projectMenu->addAction(this->projectRemoveItemAction);
        this->projectMenu->addSeparator();
        this->projectMenu->addAction(this->projectDeleteItemAction);
        
        
        this->buildBuildWorkspaceAction = new QAction("Build Workspace", this);
        this->buildCleanWorkspaceAction = new QAction("Clean Workspace", this);
        this->buildRebuildWorkspaceAction = new QAction("Rebuild Workspace", this);
        this->buildBuildProjectAction = new QAction("Build Project", this);
        this->buildCleanProjectAction = new QAction("Clean Project", this);
        this->buildRebuildProjectAction = new QAction("Rebuild Project", this);
        this->buildCompileAction = new QAction("Compile", this);
        this->buildBatchBuildAction = new QAction("Batch Build ...", this);
        
        this->buildMenu->addAction(this->buildBuildWorkspaceAction);
        this->buildMenu->addAction(this->buildCleanWorkspaceAction);
        this->buildMenu->addAction(this->buildRebuildWorkspaceAction);
        this->buildMenu->addSeparator();
        this->buildMenu->addAction(this->buildBuildProjectAction);
        this->buildMenu->addAction(this->buildCleanProjectAction);
        this->buildMenu->addAction(this->buildRebuildProjectAction);
        this->buildMenu->addSeparator();
        this->buildMenu->addAction(this->buildCompileAction);
        this->buildMenu->addSeparator();
        this->buildMenu->addAction(this->buildBatchBuildAction);
        
        this->debugStartWithoutDebuggingAction = new QAction("Start Without Debugging", this);
        this->debugStartAction = new QAction("Start", this);
        this->debugStopAction = new QAction("Stop", this);
        this->debugPauseAction = new QAction("Pause", this);
        this->debugRestartAction = new QAction("Restart", this);
        this->debugToggleBreakpointAction = new QAction("Toggle Breakpoint", this);
        this->debugStepInAction = new QAction("Step In", this);
        this->debugStepOutAction = new QAction("Step Out", this);
        this->debugStepOverAction = new QAction("Step Over", this);
        this->debugRunToCursorAction = new QAction("Run up to cursor", this);
        
        this->debugMenu->addAction(this->debugStartWithoutDebuggingAction);
        this->debugMenu->addSeparator();
        this->debugMenu->addAction(this->debugStartAction);
        this->debugMenu->addAction(this->debugStopAction);
        this->debugMenu->addAction(this->debugPauseAction);
        this->debugMenu->addAction(this->debugRestartAction);
        this->debugMenu->addSeparator();
        this->debugMenu->addAction(this->debugToggleBreakpointAction);
        this->debugMenu->addSeparator();
        this->debugMenu->addAction(this->debugStepInAction);
        this->debugMenu->addAction(this->debugStepOutAction);
        this->debugMenu->addAction(this->debugStepOverAction);
        this->debugMenu->addAction(this->debugRunToCursorAction);
        
        this->toolsPluginsAction = new QAction("Plugins", this);
        this->toolsToolchainOptionsAction = new QAction("Toolchain Options ...", this);
        this->toolsEditorOptionsAction = new QAction("Editor Options ...", this);
        this->toolsIDEOptionsAction = new QAction("IDE Options ...", this);
        
        this->toolsMenu->addAction(this->toolsPluginsAction);
        this->toolsMenu->addSeparator();
        this->toolsMenu->addAction(this->toolsToolchainOptionsAction);
        this->toolsMenu->addAction(this->toolsEditorOptionsAction);
        this->toolsMenu->addAction(this->toolsIDEOptionsAction);
        
        this->helpAboutAction = new QAction("About ...", this);
        this->helpMenu->addAction(this->helpAboutAction);
        
        // Main Window Attributes
        this->setWindowTitle("Felipe's' Integrated Development Environment");
        QRect geo = {37, 37, 640 + 37, 480 + 37};
        this->setGeometry(geo);
        
        // Create support controls
        this->setCentralWidget( new EditorWidgetManager() );
        
        this->projectDockWidget = new ProjectDockWidget(tr("Holanda"), this);
        this->addDockWidget( Qt::LeftDockWidgetArea,  this->projectDockWidget );
    }
    
    
    void MainWindow::connectSignals() {
        this->connect(this->fileExitAction, SIGNAL(triggered()), this, SLOT(close()));
        
        this->connect(this->fileNewAction, SIGNAL(triggered()), this, SLOT(fileNewTriggered()));
    }
    
    
    void MainWindow::fileNewTriggered() {
        
    }
}}
