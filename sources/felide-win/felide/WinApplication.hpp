
#pragma once 

#ifndef __felide_winapplication_hpp__
#define __felide_winapplication_hpp__

#include <felide/Application.hpp>
#include <wcl/WindowClass.hpp>

namespace felide {
    class WinApplication : public Application {
    public:
        WinApplication();

        ~WinApplication();
        
        int run(int argc, char **argv);
    };
}

#endif
