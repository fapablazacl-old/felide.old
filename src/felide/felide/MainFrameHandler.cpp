
#include "MainFrameHandler.hpp"

#include <iostream>

namespace felide {
    MainFrameHandler::MainFrameHandler() {}

    MainFrameHandler::~MainFrameHandler() {}

    void MainFrameHandler::handleFileExit() {
        std::cout << "MainFrameHandler::handleFileExit" << std::endl;
    }

    void MainFrameHandler::handleToolPlugins() {
        std::cout << "MainFrameHandler::handleToolPlugins" << std::endl;
    }

    HandlerMethodMap MainFrameHandler::buildMap() {
        return {
            {"file.exit", [this](){this->handleFileExit();} },
            {"tools.plugins", [this](){this->handleToolPlugins();}}
        };
    }
}
