
#pragma once

#ifndef __felide_mainpanel_hpp__
#define __felide_mainpanel_hpp__

#include <QWidget>
#include <QDockWidget>

namespace felide {
    class MainPanel : public QWidget {
        Q_OBJECT

    public:
        MainPanel(QWidget *parent);

        ~MainPanel();

    private:
        QDockWidget *m_dockWidget = nullptr;
    };
}


#endif
