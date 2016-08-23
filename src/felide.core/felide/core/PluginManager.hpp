
#ifndef __felide_core_pluginmanager_hpp__
#define __felide_core_pluginmanager_hpp__

#include "Plugin.hpp"
#include "Locator.hpp"

#include <memory>
#include <list>

namespace felide {  namespace core {
    class Application;
    class PluginManager {
    public:
        explicit PluginManager(Application* application);

        ~PluginManager();

        Application* getApplication() {
            return m_application;
        }

        Locator* getLocator() {
            return &m_locator;
        }

        void load(const std::string &name);

        void unload(const std::string &name);

    private:
        Application *m_application = nullptr;
        Locator m_locator;

        std::list<std::unique_ptr<Plugin>> m_plugins;
    };
}}

#endif 
