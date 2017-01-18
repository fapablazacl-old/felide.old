
#pragma once 

#ifndef __felide_winapplication_hpp__
#define __felide_winapplication_hpp__

#include <felide/Application.hpp>

namespace felide {
    class WinApplication : public Application {
    public:
        WinApplication();

        int run(int argc, char **argv);

        ~WinApplication();
    };
}

#endif
