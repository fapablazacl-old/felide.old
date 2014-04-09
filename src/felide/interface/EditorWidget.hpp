/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#ifndef __FELIDE_INTERFACE_EDITORWIDGET_HPP__
#define __FELIDE_INTERFACE_EDITORWIDGET_HPP__

#include <QWidget>

namespace felide { namespace interface {
    class EditorWidget : public QWidget {
        Q_OBJECT
    public:
        explicit EditorWidget(QWidget *parent = 0);
        
    signals:
        
    public slots:
        
    };
}}

#endif // __FELIDE_INTERFACE_EDITORWIDGET_HPP__
