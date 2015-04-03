
#ifndef __FELIDE_VIEW_MAINWINDOW_HPP__
#define __FELIDE_VIEW_MAINWINDOW_HPP__

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QTabWidget>

#include <felide/view/Editor.hpp>
#include <felide/view/EditorPanel.hpp>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    class MainWindow : public QMainWindow {
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
        int askSaveChanges(Editor *editor);
        
        void updateTitle();
        
        /**
         * @brief Check if the user wants to save the specified editor data
         */
        bool saveChanges(Editor *editor);
        
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
        
        EditorPanel *editorPanel = nullptr;
        
        int documentCount = 1;
        
    private slots:
        void onNewFile();
        bool onOpenFile();
        bool onSaveFile(Editor *editor);
        bool onSaveFileAs(Editor *editor);
        void onExit();
        
        /**
         * @brief Try to close the specified editor. Return 'true' if the editor 
         * can be closed, and 'false' otherwise.
         */
        bool onClose(Editor *editor);
        
        void onUndo(Editor *editor);
        void onRedo(Editor *editor);
        void onCut(Editor *editor);
        void onCopy(Editor *editor);
        void onPaste(Editor *editor);
        
        void onTest();
        
        void onBuild();
        void onExecute();
    };
}}

#endif  // __FELIDE_VIEW_MAINWINDOW_HPP__
