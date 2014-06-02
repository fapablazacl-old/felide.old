/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

//    piemioteadoroooo

#include <iostream>
#include <boost/make_shared.hpp>

#include <felide/interface/MainWindow.hpp>
#include <felide/interface/EditorWidgetManager.hpp>

namespace felide { namespace gui {
    MainWindow::MainWindow() : ui( new Ui::MainWindow() ) {
        this->ui->setupUi(this);
    }
}}
