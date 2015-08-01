
#ifndef __felide_editor_qt5_application_hpp__
#define __felide_editor_qt5_application_hpp__

#include "felide.editor/Application.hpp"

namespace felide { namespace editor { namespace qt5 {

    class Application : public felide::editor::Application {
    public:
        virtual int run(int argc, char **argv) override;
    };
}}}

#endif  // __felide_editor_qt5_application_hpp__
