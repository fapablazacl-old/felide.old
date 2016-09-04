
#ifndef __felide_core_view_frame_hpp__
#define __felide_core_view_frame_hpp__

#include <cstddef>
#include <felide/PreDef.hpp>
#include <felide/Menu.hpp>

namespace felide {

    class FELIDE_CORE_API FrameHandler;
    class FELIDE_CORE_API Editor;
    class FELIDE_CORE_API Frame {
    public:
        virtual ~Frame();
        
        virtual void setMenu(const Menu &menu) = 0;

        virtual void setHandler(FrameHandler *handler) = 0;

        virtual FrameHandler* getHandler() = 0;
    };
}

#endif 
