
#ifndef __felide_qt5_mainwindow_hpp__
#define __felide_qt5_mainwindow_hpp__

#include <memory>
#include <list>
#include <QMainWindow>
#include <felide/ProjectItem.hpp>

#include "ui_MainWindow.h"
#include "TabbedEditor.hpp"

namespace felide { namespace qt5 {

    class MainWindow : public QMainWindow {
        Q_OBJECT
        
    public:
        MainWindow();
        virtual ~MainWindow();

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
        TabbedEditor *tabbedEditor = nullptr;
        
        std::list<ProjectItemPtr> items;
        
        int untitledCount = 0;
    };
}}

#endif  // __felide_qt5_mainwindow_hpp__
