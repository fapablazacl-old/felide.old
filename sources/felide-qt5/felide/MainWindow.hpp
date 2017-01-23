
#pragma once

#ifndef __felide_mainwindow_hpp__
#define __felide_mainwindow_hpp__

#include <QMainWindow>
#include <memory>

namespace felide {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    private:
        struct Private;
        std::unique_ptr<Private> m_impl;
    };
}

#endif
