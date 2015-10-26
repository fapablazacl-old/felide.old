
#ifndef __felide_editor_application_hpp__
#define __felide_editor_application_hpp__

#include "felide/Config.hpp"

namespace felide { namespace editor {

    class FELIDE_API Application {
    public:
        Application();
        virtual ~Application();
        
        virtual int run(int argc, char **argv) = 0;
    };
}}

#endif	// __felide_application_hpp__
