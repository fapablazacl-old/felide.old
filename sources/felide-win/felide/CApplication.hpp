
#pragma once 

#ifndef __felide_capplication_hpp__
#define __felide_capplication_hpp__

#include <felide/Application.hpp>

namespace felide {
    class CApplication : public Application {
    public:
        CApplication();

        int run(int argc, char **argv);

        ~CApplication();
    };
}

#endif
