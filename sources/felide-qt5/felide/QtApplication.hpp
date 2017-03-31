
#pragma once 

#ifndef __felide_qtapplication_hpp__
#define __felide_qtapplication_hpp__

#include <felide/Application.hpp>

namespace felide {
    class QtApplication : public Application {
    public:
        int run(int argc, char **argv);
    };
}

#endif 
