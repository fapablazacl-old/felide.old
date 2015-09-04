
#ifndef __felide_qt5_mainwindow_hpp__
#define __felide_qt5_mainwindow_hpp__

#include <memory>
#include <list>
#include <QMainWindow>
#include <felide/ProjectItem.hpp>

#include "ui_MainWindow.h"
#include "QTabbedEditor.hpp"

namespace felide { namespace qt5 {

    class QMainWindow : public ::QMainWindow {
        Q_OBJECT

    public:
        QMainWindow();
        virtual ~QMainWindow();

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
