
#pragma once

#ifndef __felide_plugin_hpp__
#define __felide_plugin_hpp__

#include <string>

namespace felide {
    class Plugin {
    public:
        virtual ~Plugin();

        virtual std::string getName() const = 0;
    };
}

#endif 
