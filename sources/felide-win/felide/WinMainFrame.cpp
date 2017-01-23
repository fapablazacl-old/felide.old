
#include "WinMainFrame.hpp"

#include <wcl/gen/Menu.hpp>

namespace felide {

    wcl::WindowClass* WinMainFrame::GetWindowClass() {
        static auto class_ = wcl::WindowClass::MakeDefault("Frame", wcl::Window::WndProc);
        return &class_;
    }

    WinMainFrame::WinMainFrame() : Window("Frame") {}

    LRESULT WinMainFrame::Procedure(UINT Msg, WPARAM wParam, LPARAM lParam) {
        switch (Msg) {
        case WM_CREATE:

            break;


        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        }

        return Window::Procedure(Msg, wParam, lParam);
    }
}
