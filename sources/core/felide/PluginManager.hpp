
#pragma once

#ifndef __felide_pluginmanager_hpp__
#define __felide_pluginmanager_hpp__

namespace felide {
    class Plugin;
    class PluginManager {
    public:
        virtual ~PluginManager();

        virtual int getPluginCount() const = 0;

        virtual Plugin* getPlugin(const size_t index) const = 0; 
    };
}

#endif 
