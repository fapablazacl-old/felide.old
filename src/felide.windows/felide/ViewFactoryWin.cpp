
#include "ViewFactoryWin.hpp"
#include "MainFrameWin.hpp"

namespace felide { 
    ViewFactoryWin::~ViewFactoryWin() {}

    std::unique_ptr<Frame> ViewFactoryWin::createMainFrame(const std::map<std::string, std::string> *labels) {
        return std::make_unique<MainFrame>(labels);
    }

    int ViewFactoryWin::mainLoop() {
        return m_app.Run();
    }
}
