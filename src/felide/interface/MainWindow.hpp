/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_INTERFACE_MAINWINDOW_HPP__
#define __FELIDE_INTERFACE_MAINWINDOW_HPP__

#include <memory>
#include <boost/shared_ptr.hpp>
#include <felide/projects/Workspace.hpp>

#include <QMainWindow>

#include "ui_MainWindow.h"

namespace felide { namespace gui {
	class MainWindow : public QMainWindow {
    public:
        MainWindow();

    private:
        std::unique_ptr<Ui::MainWindow> ui;
        boost::shared_ptr<felide::projects::Workspace> workspace;
    };
}}

#endif // __FELIDE_INTERFACE_MAINWINDOW_HPP__
