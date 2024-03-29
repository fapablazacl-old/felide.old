
#pragma once

#ifndef __felide_winmainframe_hpp__
#define __felide_winmainframe_hpp__

#include <wcl/WindowClass.hpp>
#include <wcl/Window.hpp>
#include <wcl/Menu.hpp>

namespace felide {
    class WinMainFrame : public wcl::Window {
    public:
        static wcl::WindowClass* GetWindowClass();

        virtual LRESULT Procedure(UINT Msg, WPARAM wParam, LPARAM lParam) override;

        WinMainFrame();

    private:
        wcl::MenuPtr m_menuBar;
    };
}

#endif
