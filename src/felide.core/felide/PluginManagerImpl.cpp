
#include "PluginManagerImpl.hpp"

#include <felide/Application.hpp>

#include "ArbitraryLocator.hpp"
#include "PluginLibrary.hpp"

#include <cstdlib>

namespace felide {
    static std::string buildPluginFileName(const std::string &name) {
#if defined(_WIN32)
        return name + ".dll";
#else 
        return "lib" + name + ".so";
#endif
    }

    PluginManagerImpl::PluginManagerImpl(Application* application) 
        : m_application(application) {

        m_locator.reset(new ArbitraryLocator());
    }

    PluginManagerImpl::~PluginManagerImpl() {}

    void PluginManagerImpl::load(const std::string &name) {
        std::string fileName = buildPluginFileName(name);

        auto library = m_application->getSystemFactory()->loadLibrary(fileName);
        auto plugin = std::make_unique<PluginLibrary>(std::move(library));
        
        plugin->start(m_application);

        m_plugins.insert({name, std::move(plugin)});
    }

    void PluginManagerImpl::unload(const std::string &name) {
        auto pluginPos = m_plugins.find(name);

        if (pluginPos == m_plugins.end()) {
            // TODO: plugin not found!
        }

        pluginPos->second->stop(m_application);

        m_plugins.erase(pluginPos);
    }
}
