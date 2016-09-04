
#pragma once

#ifndef __felide_core_locator_hpp__
#define __felide_core_locator_hpp__

#include <string>
#include <list>

namespace felide { 
    class Locator {
    public:
        virtual ~Locator();
        virtual std::string locate(const std::string &name) = 0;
    };
}

#endif
