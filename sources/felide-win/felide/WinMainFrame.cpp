
#include "WinMainFrame.hpp"

namespace felide {
    WinMainFrame::WinMainFrame() : wcl::Frame(L"WinMainFrame") {
        
    }

    void WinMainFrame::OnClose() {
        this->PostMessage_(WM_QUIT);
    }
}
