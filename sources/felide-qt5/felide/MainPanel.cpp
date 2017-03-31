
#include "MainPanel.hpp"

namespace felide {
    MainPanel::MainPanel(QWidget *parent) : QWidget(parent) {
        m_dockWidget = new QDockWidget(this);
    }

    MainPanel::~MainPanel() {}
}
