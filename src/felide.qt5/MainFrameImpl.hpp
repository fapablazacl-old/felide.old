
#ifndef __felide_editor_qt5_qmainframe_hpp__
#define __felide_editor_qt5_qmainframe_hpp__

#include <memory>
#include <list>
#include <QMainWindow>
#include <QToolBox>

#include <felide/ProjectItem.hpp>
#include <felide/view/Editor.hpp>
#include <felide/view/MainFrame.hpp>

#include "ui_MainFrame.h"
#include "TabbedEditor.hpp"

namespace felide { namespace view { namespace qt5 {

    class AppImpl;
    class MainFrameImpl : public QMainWindow, public MainFrame {
        Q_OBJECT

    public:
        using MainFrame::close;

        explicit MainFrameImpl(AppImpl *appImpl);
        virtual ~MainFrameImpl() {}

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
            
        }
        
        virtual std::string getEditorTitle(Editor *view) const  override {
            return "";
        }
        
        virtual void updateEnableStatus() override;
		
    private:
        std::unique_ptr<Ui_MainWindow> m_ui;
        TabbedEditor *m_tabbedEditor = nullptr;
        AppImpl *m_appImpl = nullptr;
    };
}}}

#endif  // __felide_qt5_mainwindow_hpp__
