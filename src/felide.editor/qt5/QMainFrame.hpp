
#ifndef __felide_qt5_mainwindow_hpp__
#define __felide_qt5_mainwindow_hpp__

#include <memory>
#include <list>
#include <QMainWindow>
#include <felide/ProjectItem.hpp>

#include "felide.editor/MainFrame.hpp"

#include "ui_QMainFrame.h"
#include "QTabbedEditor.hpp"

namespace felide { namespace qt5 {

    class QMainFrame : public ::QMainWindow, public felide::editor::MainFrame {
        Q_OBJECT

    public:
        using MainFrame::close;
    
        QMainFrame(felide::editor::DialogFactory *factory);
        virtual ~QMainFrame();

    public:
        virtual void close() override;
        virtual felide::editor::Editor* createEditor(ProjectItemPtr item) override;
        
		virtual felide::editor::Editor* getCurrentEditor() override;
		virtual const felide::editor::Editor* getCurrentEditor() const override;
        
    public slots:
        void handleFileNew();
        void handleFileOpen();
        void handleFileSave();
        void handleFileSaveAs();
        void handleFileClose();
        void handleFileExit();

    private:
        void updateState();

    private:
        std::unique_ptr<Ui_MainWindow> ui;
        QTabbedEditor *tabbedEditor = nullptr;

        std::list<ProjectItemPtr> items;

        int untitledCount = 0;
    };
}}

#endif  // __felide_qt5_mainwindow_hpp__
