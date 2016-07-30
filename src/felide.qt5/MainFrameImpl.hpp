
#ifndef __felide_editor_qt5_qmainframe_hpp__
#define __felide_editor_qt5_qmainframe_hpp__

#include <memory>
#include <list>
#include <iostream>
#include <QMainWindow>
#include <QToolBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QDockWidget>

#include "felide/ProjectItem.hpp"
#include "felide/view/Editor.hpp"
#include "felide/view/MainFrame.hpp"
#include "felide/Workspace.hpp"

#include "TabbedEditor.hpp"
#include "WorkspaceView.hpp"

namespace felide { namespace view { namespace qt5 {

    class AppImpl;
    class MainFrameImpl : public QMainWindow, public MainFrame {
        Q_OBJECT

    public:
        using MainFrame::close;

        explicit MainFrameImpl(AppImpl *appImpl);
        virtual ~MainFrameImpl() {}

    private:
        void setupDockUI();
        
        void setupMenuHandlers();
        
        void setupMenus();
        
    public:
        virtual App* getApp() override;
        
        virtual const App* getApp() const override;
        
        virtual void close() override {
            QMainWindow::close();
        }
        
        virtual Editor* createEditor(ProjectItemPtr item) override {
            return m_tabbedEditor->openEditor(std::move(item));
        }
        
        virtual void closeEditor(Editor* view) override {
            m_tabbedEditor->closeEditor(static_cast<EditorImpl*>(view));
        }

        virtual Editor* getCurrentEditor() override {
            return m_tabbedEditor->getCurrentEditor();
        }
        
        virtual const Editor* getCurrentEditor() const override {
            return m_tabbedEditor->getCurrentEditor();
        }

        virtual int getEditorCount() const override {
            return m_tabbedEditor->getEditorCount();
        }
        
        virtual Editor* getEditor(const int index) override {
            return m_tabbedEditor->getEditor(index);
        }
        
        virtual const Editor* getEditor(const int index) const override {
            return m_tabbedEditor->getEditor(index);
        }

        virtual void setEditorTitle(Editor *view, const std::string &title) override {
            m_tabbedEditor->setEditorTitle(view, title.c_str());
        }
        
        virtual std::string getEditorTitle(Editor *view) const  override {
            std::cout << "MainFrameImpl::getEditorTitle: Not implemented" << std::endl;
            
            return "";
        }
        
        virtual void updateEnableStatus() override;
		
    public:
        void loadDefaultWorkspace();
        
    private:
        TabbedEditor *m_tabbedEditor = nullptr;
        AppImpl *m_appImpl = nullptr;
        WorkspacePtr m_workspace;
        
        enum ActionIdentifiers {
            MenuSeparator = -1,
            FileNew,
            FileOpen,
            FileSave,
            FileSaveAs,
            FileSaveAll,
            FileClose,
            FileExit,

            EditUndo,
            EditRedo,
            EditCut,
            EditCopy,
            EditPaste,

            ViewWorkspace,
            ViewOutput,
            ViewTotal,

            BuildClean,
            BuildExecute,
            
            HelpAbout,
            HelpTotal
        };
        
        QAction *m_actions[HelpTotal] = {};
        
        QMenu *m_fileMenu = nullptr;
        QMenu *m_editMenu = nullptr;
        QMenu *m_viewMenu = nullptr;
        QMenu *m_buildMenu = nullptr;
        QMenu *m_helpMenu = nullptr;
        
        QMenuBar *m_menuBar = nullptr;
        
        QDockWidget *m_workspaceDock = nullptr;
        QDockWidget *m_outputDock = nullptr;        

        WorkspaceView *m_workspaceView = nullptr;
        QPlainTextEdit *m_outputTextEdit = nullptr;
    };
}}}

#endif  // __felide_qt5_mainwindow_hpp__
