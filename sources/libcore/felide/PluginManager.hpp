
#pragma once

#ifndef __felide_pluginmanager_hpp__
#define __felide_pluginmanager_hpp__

#include <cstddef>

namespace felide {
    class Plugin;

    /**
     * @brief Management for Plugins - the core of the IDE extensibility
     */
    class PluginManager {
    public:
        virtual ~PluginManager();

        /**
         * @brief Returns the total amount of loaded plugins.
         */
        virtual std::size_t getPluginCount() const = 0;

        /**
         * @brief Return a plugin interface located at the specified index.
         */
        virtual Plugin* getPlugin(const std::size_t index) const = 0;
    };
}

#endif
