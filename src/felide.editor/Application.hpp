
#ifndef __felide_editor_application_hpp__
#define __felide_editor_application_hpp__

#include <memory>

#include "DialogFactory.hpp"

namespace felide { namespace editor {

    class Application {
    public:
        Application();
        virtual ~Application();
        
        virtual void initialize(int argc, char **argv);
        virtual int execute(int argc, char **argv) = 0;
        
    public:
        static int run(int argc, char **argv);
    };
}}

#endif	// __felide_application_hpp__
