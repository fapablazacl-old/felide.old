/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#ifndef __FELIDE_INTERFACE_EDITORWIDGETMANAGER_HPP__
#define __FELIDE_INTERFACE_EDITORWIDGETMANAGER_HPP__

#include <QTabWidget>

namespace felide { namespace interface {
    /**
     * @brief The central widget in the window.
     */
    class EditorWidgetManager : public QTabWidget {
        Q_OBJECT
    public:
        explicit EditorWidgetManager(QWidget *parent = nullptr);
        
        /**
         * @brief Opens a new tab, with an empty document.
         */
        void open();
        
    private:
        
        
    signals:
        
    public slots:
    
    };

}}

#endif // __FELIDE_INTERFACE_EDITORWIDGETMANAGER_HPP__
