
#include "PluginFrameWin.hpp"

namespace felide {
    PluginFrameWin::PluginFrameWin() : wcl::Frame(L"felide::PluginFrameWin") {
        this->Create(L"P", WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    }

    PluginFrameWin::~PluginFrameWin() {

    }

    void PluginFrameWin::OnCreate() {
        
    }
}
