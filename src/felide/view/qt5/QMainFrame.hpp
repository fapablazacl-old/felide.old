
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

namespace felide { namespace view { namespace qt5 {

    class QMainFrame : public ::QMainWindow, public felide::view::MainFrame {
        Q_OBJECT

    public:
        using MainFrame::close;

        QMainFrame(felide::view::DialogFactory *factory);
        virtual ~QMainFrame();

    public:
        virtual void close() override;
        virtual felide::view::Editor* createEditor(ProjectItemPtr item) override;
        virtual void closeEditor(Editor* view) override;

		virtual felide::view::Editor* getCurrentEditor() override;
		virtual const felide::view::Editor* getCurrentEditor() const override;

        virtual int getEditorCount() const override;
		virtual Editor* getEditor(const int index) override;
		virtual const Editor* getEditor(const int index) const override;

		virtual void updateEnableStatus() override;

        virtual void setEditorTitle(Editor *view, const std::string &title) override;
		virtual std::string getEditorTitle(Editor *view) const  override;
		
    private:
        std::unique_ptr<Ui_MainWindow> ui;
        QTabbedEditor *tabbedEditor = nullptr;
    };
}}}

#endif  // __felide_qt5_mainwindow_hpp__
