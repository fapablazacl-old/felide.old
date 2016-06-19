#pragma once

#ifndef QMAINPANEL_HPP
#define QMAINPANEL_HPP

#include <QWidget>
#include <QToolBox>

namespace felide { namespace view { namespace qt5 {
    
    class QMainPanel : public QWidget {
        Q_OBJECT
    public:
        explicit QMainPanel(QWidget *parent = 0);
        
    private:
        QToolBox *toolBox = nullptr;
        
        
    signals:
        
    public slots:
        
    };

}}}

#endif // QMAINPANEL_HPP
