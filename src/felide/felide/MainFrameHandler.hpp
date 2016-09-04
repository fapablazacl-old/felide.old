
#ifndef __felide_mainframehandler_hpp__
#define __felide_mainframehandler_hpp__

#include <felide/view/FrameHandler.hpp>

namespace felide {
    class MainFrameHandler : public felide::core::view::FrameHandler {
    public:
        MainFrameHandler();

        virtual ~MainFrameHandler();

        void handleFileExit();

        virtual felide::core::view::HandlerMethodMap buildMap() override;
    };
}

#endif
