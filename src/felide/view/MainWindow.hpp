
#ifndef __FELIDE_VIEW_MAINWINDOW_HPP__
#define __FELIDE_VIEW_MAINWINDOW_HPP__

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QTabWidget>

#include <felide/view/SourceEditor.hpp>
#include <felide/view/EditorPanel.hpp>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    class MainWindow : public QMainWindow 
    {
        Q_OBJECT
        
    public:
        MainWindow();
        ~MainWindow();
        
        virtual void closeEvent(QCloseEvent *event) override;
        
    private:
        void initializeUserInterface();
        
        void initializeMenuBar();
        void connectSignals();
        
        void updateEditorMargin();
        int askSaveChanges();
        
        void updateTitle();
        
    private:
        QMenu *fileMenu = nullptr;
        QMenu *editMenu = nullptr;
        QMenu *testMenu = nullptr;
        QMenu *compileMenu = nullptr;
        
        QAction *newFileAction = nullptr;
        QAction *openFileAction = nullptr;
        QAction *saveFileAction = nullptr;
        QAction *saveAsFileAction = nullptr;
        QAction *exitAction = nullptr;
        
        QAction *undoAction = nullptr;
        QAction *redoAction = nullptr;
        QAction *cutAction = nullptr;
        QAction *copyAction = nullptr;
        QAction *pasteAction = nullptr;
        
        QAction *testAction = nullptr;
        
        QAction *buildAction = nullptr;
        QAction *executeAction = nullptr;
		// SourceEditor *sourceEditor = nullptr;
        
        EditorPanel *editorPanel;
        
        int documentCount = 1;
        
    private slots:
        void onNewFile();
        bool onOpenFile();
        bool onSaveFile();
        bool onSaveFileAs();
        void onExit();
        
        void onEditorChanged(const QString &title);
        
        void onUndo();
        void onRedo();
        void onCut();
        void onCopy();
        void onPaste();
        
        void onTest();
        
        void onBuild();
        void onExecute();
    };
}}

#endif  // __FELIDE_VIEW_MAINWINDOW_HPP__
