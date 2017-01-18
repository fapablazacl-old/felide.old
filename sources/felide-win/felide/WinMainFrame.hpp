
#pragma once

#ifndef __felide_winmainframe_hpp__
#define __felide_winmainframe_hpp__

#include <wcl/Frame.hpp>

namespace felide {
    class WinMainFrame : public wcl::Frame {
    public:
        WinMainFrame();

        virtual void OnClose() override;
    };
}

#endif
