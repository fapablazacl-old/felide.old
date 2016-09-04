
#ifndef __felide_mainframehandler_hpp__
#define __felide_mainframehandler_hpp__

#include <felide/FrameHandler.hpp>

namespace felide {
    class MainFrameHandler : public FrameHandler {
    public:
        MainFrameHandler();

        virtual ~MainFrameHandler();

        void handleFileExit();

        virtual HandlerMethodMap buildMap() override;
    };
}

#endif
