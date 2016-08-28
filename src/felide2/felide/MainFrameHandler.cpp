
#include "MainFrameHandler.hpp"

#include <iostream>

namespace felide {

    MainFrameHandler::MainFrameHandler() {}

    MainFrameHandler::~MainFrameHandler() {}

    void MainFrameHandler::handleFileExit() {
        std::cout << "MainFrameHandler::handleFileExit" << std::endl;
    }

    felide::core::view::HandlerMethodMap MainFrameHandler::buildMap() {
        return {
            {"file.exit", [this](){this->handleFileExit();} }
        };
    }
}
