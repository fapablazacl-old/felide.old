
#include <felide/Frame.hpp>
#include <wcl/Frame.hpp>

namespace felide {
    class PluginFrameWin : public Frame, public wcl::Frame {
    public:
        PluginFrameWin();

        virtual ~PluginFrameWin();

        virtual void setMenu(const Menu &menu) override {}

        virtual void setHandler(FrameHandler *handler) override {}

        virtual FrameHandler* getHandler() override {
            return nullptr;
        }

    public:
        virtual void OnCreate() override;
    };
}
