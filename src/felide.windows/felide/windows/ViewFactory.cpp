
#include "ViewFactory.hpp"
#include "MainFrame.hpp"

namespace felide { namespace windows {
    ViewFactory::~ViewFactory() {}

    std::unique_ptr<felide::core::view::Frame> ViewFactory::createMainFrame(const std::map<std::string, std::string> *labels) {
        return std::make_unique<MainFrame>(labels);
    }

    int ViewFactory::mainLoop() {
        return m_app.Run();
    }
}}
