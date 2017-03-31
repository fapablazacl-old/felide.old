
#ifndef __felide_core_pluginmanagerimpl_hpp__
#define __felide_core_pluginmanagerimpl_hpp__

#include "Plugin.hpp"
#include "Locator.hpp"
#include "PluginManager.hpp"

#include <memory>
#include <list>
#include <map>

namespace felide {
    class Application;
    class PluginManagerImpl : public PluginManager {
    public:
        explicit PluginManagerImpl(Application* application);

        virtual ~PluginManagerImpl();

        virtual Application* getApplication() {
            return m_application;
        }

        virtual Locator* getLocator() {
            return m_locator.get();
        }

        virtual void load(const std::string &name);

        virtual void unload(const std::string &name);

    private:
        Application *m_application = nullptr;
        std::unique_ptr<Locator> m_locator;

        std::map<std::string, std::unique_ptr<Plugin>> m_plugins;
    };
}

#endif 
