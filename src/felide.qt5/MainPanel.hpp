#pragma once

#ifndef QMAINPANEL_HPP
#define QMAINPANEL_HPP

#include <QWidget>
#include <QToolBox>

namespace felide { namespace view { namespace qt5 {
    
    class MainPanel : public QWidget {
        Q_OBJECT
    public:
        explicit MainPanel(QWidget *parent = 0);
        
    private:
        QToolBox *m_toolBox = nullptr;
        
        
    signals:
        
    public slots:
        
    };

}}}

#endif // QMAINPANEL_HPP
