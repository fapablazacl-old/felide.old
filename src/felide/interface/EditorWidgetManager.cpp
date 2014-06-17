/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#include <felide/interface/EditorWidgetManager.hpp>
#include <QTabWidget>

namespace felide { namespace interface { 
    EditorWidgetManager::EditorWidgetManager(QWidget *parent) : QWidget(parent) {
        QTabWidget *tabWidget = new QTabWidget(this);
        tabWidget->addTab(new QWidget(this), "Uno ");
    }
}}
