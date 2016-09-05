
#include "ViewFactoryWin.hpp"

#include "MainFrameWin.hpp"
#include "PluginFrameWin.hpp"

namespace felide { 
    ViewFactoryWin::~ViewFactoryWin() {}

    std::unique_ptr<Frame> ViewFactoryWin::createMainFrame(const std::map<std::string, std::string> *labels) {
        return std::make_unique<MainFrameWin>(labels);
    }

    std::unique_ptr<Frame> ViewFactoryWin::createPluginFrame(PluginManager *pluginManager) {
        return std::make_unique<PluginFrameWin>();
    }

    int ViewFactoryWin::mainLoop() {
        return m_app.Run();
    }
}
