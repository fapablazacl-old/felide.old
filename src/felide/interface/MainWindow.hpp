/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#ifndef __FELIDE_INTERFACE_MAINWINDOW_HPP__
#define __FELIDE_INTERFACE_MAINWINDOW_HPP__

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuItem>
#include <QDockWidget>

#include <boost/shared_ptr.hpp>

#include <felide/interface/ProjectDockWidget.hpp>
#include <felide/projects/Workspace.hpp>

namespace felide { namespace interface {

    class MainWindow : public QMainWindow {
        Q_OBJECT
        
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        
    private:
        void setupUi();
        void connectSignals();
        
    private:
        boost::shared_ptr<felide::projects::Workspace> workspace;
        
    private:
        QMenu *fileMenu, *editMenu, *viewMenu, *projectMenu;
        QMenu *buildMenu, *debugMenu, *toolsMenu, *helpMenu;
        
        QAction *fileNewAction, *fileOpenAction, *fileSaveAction;
        QAction *fileSaveAllAction, *fileCloseAction, *fileCloseProjectAction;
        QAction *filePrintAction, *fileExitAction;
        
        QAction *editUndoAction, *editRedoAction, *editCutAction;
        QAction *editCopyAction, *editPasteAction, *editDeleteAction;
        QAction *editSelectAllAction;
        
        QAction *viewProjectViewAction, *viewClassViewAction, *viewOutputWindowAction;
        QAction *viewErrorListWindowAction;
        
        QAction *projectAddItemAction, *projectEditItemAction;
        QAction *projectRemoveItemAction, *projectDeleteItemAction;
        
        QAction *buildBuildWorkspaceAction, *buildCleanWorkspaceAction, *buildRebuildWorkspaceAction;
        QAction *buildBuildProjectAction, *buildCleanProjectAction, *buildRebuildProjectAction;
        QAction *buildCompileAction, *buildBatchBuildAction;
        
        QAction *debugStartWithoutDebuggingAction;
        QAction *debugStartAction, *debugStopAction, *debugPauseAction, *debugRestartAction;
        QAction *debugToggleBreakpointAction;
        QAction *debugStepInAction, *debugStepOutAction, *debugStepOverAction, *debugRunToCursorAction;
        
        QAction *toolsPluginsAction, *toolsToolchainOptionsAction;
        QAction *toolsEditorOptionsAction, *toolsIDEOptionsAction;
        
        QAction *helpAboutAction;
        
        ProjectDockWidget *projectDockWidget;
        
    signals:
        
    public slots:
        void fileNewTriggered();
    };
}}

#endif // __FELIDE_INTERFACE_MAINWINDOW_HPP__
