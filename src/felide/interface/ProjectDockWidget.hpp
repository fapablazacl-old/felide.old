/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#ifndef __FELIDE_INTERFACE_PROJECTDOCKWIDGET_HPP__
#define __FELIDE_INTERFACE_PROJECTDOCKWIDGET_HPP__

#include <QDockWidget>
#include <QTreeView>

namespace felide { namespace interface {
    class ProjectDockWidget : public QDockWidget {
        Q_OBJECT
    public:
        explicit ProjectDockWidget(const QString &title = tr(""), QWidget *parent = nullptr);
    
    private:
        QTreeView *treeView;
        
    signals:
        
    public slots:
        
    };
}}

#endif // __FELIDE_PROJECTDOCKWIDGET_HPP__
