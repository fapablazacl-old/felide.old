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

#include <boost/shared_ptr.hpp>
#include <felide/projects/Workspace.hpp>

#include <wx/frame.h>

namespace felide { namespace gui {
	class MainWindow : public wxFrame {
    public:
        MainWindow();

    private:
        boost::shared_ptr<felide::projects::Workspace> workspace;
    };
}}

#endif // __FELIDE_INTERFACE_MAINWINDOW_HPP__
