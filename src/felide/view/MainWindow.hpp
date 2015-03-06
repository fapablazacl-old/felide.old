
#ifndef __FELIDE_VIEW_MAINWINDOW_HPP__
#define __FELIDE_VIEW_MAINWINDOW_HPP__

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <Qsci/qsciscintilla.h>

#include <QDockWidget>

#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    class MainWindow : public QMainWindow 
    {
        Q_OBJECT
        
    public:
        MainWindow();
        ~MainWindow();
        
        virtual void closeEvent(QCloseEvent *event) override;
        void addSourceEditor();
        
    private:
        void initializeUserInterface();
        
        void initializeEditor();
        void initializeMenuBar();
        void initializeWindow();
        void connectSignals();
        
        void updateTitle();
        
        void updateEditorMargin();
        
        int askSaveChanges();
        
        bool doOpenFile();
        bool doSaveFile();
        
        void setLexer(QsciLexer *lexer);
       
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
        
        QsciScintilla *editorWidget = nullptr;
        
        QDockWidget *dockWidget = nullptr;
        
        felide::model::Source source;
        
        int documentCount = 1;
        
    private slots:
        void onNewFile();
        void onOpenFile();
        void onSaveFile();
        void onSaveFileAs();
        void onExit();
        
        void onTextChanged();
        
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
