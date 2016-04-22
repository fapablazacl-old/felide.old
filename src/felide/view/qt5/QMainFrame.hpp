
#ifndef __felide_editor_qt5_qmainframe_hpp__
#define __felide_editor_qt5_qmainframe_hpp__

#include <memory>
#include <list>
#include <QMainWindow>
#include <QToolBox>

#include <felide/ProjectItem.hpp>
#include <felide/view/Editor.hpp>
#include <felide/view/MainFrame.hpp>

#include "ui_QMainFrame.h"
#include "QTabbedEditor.hpp"

namespace felide { namespace editor { namespace qt5 {

    class QMainFrame : public ::QMainWindow, public felide::editor::MainFrame {
        Q_OBJECT

    public:
        using MainFrame::close;

        QMainFrame(felide::editor::DialogFactory *factory);
        virtual ~QMainFrame();

    public:
        virtual void close() override;
        virtual felide::editor::Editor* createEditor(ProjectItemPtr item) override;
        virtual void closeEditor(Editor* editor) override;

		virtual felide::editor::Editor* getCurrentEditor() override;
		virtual const felide::editor::Editor* getCurrentEditor() const override;

        virtual int getEditorCount() const override;
		virtual Editor* getEditor(const int index) override;
		virtual const Editor* getEditor(const int index) const override;

		virtual void updateEnableStatus() override;

        virtual void setEditorTitle(Editor *editor, const std::string &title) override;
		virtual std::string getEditorTitle(Editor *editor) const  override;
		
    private:
        std::unique_ptr<Ui_MainWindow> ui;
        QTabbedEditor *tabbedEditor = nullptr;
    };
}}}

#endif  // __felide_qt5_mainwindow_hpp__
