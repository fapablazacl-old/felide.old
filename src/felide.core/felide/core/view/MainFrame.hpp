
#ifndef __felide_core_view_mainframe_hpp__
#define __felide_core_view_mainframe_hpp__

#include <cstddef>
#include <felide/core/PreDef.hpp>
#include <felide/core/view/gen/Menu.hpp>

namespace felide { namespace core { namespace view {

    class FELIDE_CORE_API FrameHandler;
    class FELIDE_CORE_API Editor;
    class FELIDE_CORE_API MainFrame {
    public:
        virtual ~MainFrame();
        
        virtual void setMenu(const felide::view::gen::Menu &menu) = 0;

        virtual void setHandler(FrameHandler *handler) = 0;

        virtual FrameHandler* getHandler() = 0;
    };
}}}

#endif 
