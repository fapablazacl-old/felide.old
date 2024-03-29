
#ifndef __felide_core_view_editor_hpp__
#define __felide_core_view_editor_hpp__

#include <cstddef>
#include <felide/PreDef.hpp>

namespace felide {

    class FELIDE_API MainFrame;
    class FELIDE_API Editor {
    public:
        Editor(MainFrame *mainFrame);

        virtual ~Editor() = 0;

    private:
        MainFrame *m_mainFrame;
    };
}

#endif 
