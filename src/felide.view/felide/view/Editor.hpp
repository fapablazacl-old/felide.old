
#ifndef __felide_core_view_editor_hpp__
#define __felide_core_view_editor_hpp__

#include <cstddef>
#include <felide/core/PreDef.hpp>

namespace felide { namespace core { namespace view {

    class FELIDE_CORE_API MainFrame;
    class FELIDE_CORE_API Editor {
    public:
        Editor(MainFrame *mainFrame);

        virtual ~Editor() = 0;

    private:
        MainFrame *m_mainFrame;
    };
}}}

#endif 
