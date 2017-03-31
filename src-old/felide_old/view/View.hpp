
#ifndef __felide_editor_view_hpp__
#define __felide_editor_view_hpp__

#include <memory>

namespace felide { namespace view {
    
    template<typename Handler>
    class View {
    public:
        explicit View() {}
        
        virtual ~View() {}

        Handler* getHandler() {
            return &m_handler;
        }

    protected:
        Handler m_handler;
    };
}}

#endif 
