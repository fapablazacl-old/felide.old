
#include "Application.hpp"

#include "Plugin.hpp"
#include "PluginManager.hpp"

#include <cassert>
#include <vector>
#include <memory>

namespace felide {

    class PluginImpl : public Plugin {
    public:
        PluginImpl(const std::string &name) 
            : m_name(name) {}

        virtual std::string getName() const override {
            return m_name;
        }

    private:
        std::string m_name;
    };

    class PluginManagerImpl : public PluginManager {
    public:
        PluginManagerImpl() {
            m_plugins.emplace_back(new PluginImpl("C++"));
            m_plugins.emplace_back(new PluginImpl("GLSL"));
        }

        virtual int getPluginCount() const override {
            return (int)m_plugins.size();
        }

        virtual Plugin* getPlugin(const size_t index) const override {
            return m_plugins[index].get();
        }

    private:
        std::vector<std::unique_ptr<Plugin>> m_plugins;
    };

    struct Application::Private {
        PluginManagerImpl m_pluginManager;
    };

    Application::Application() {
        m_impl = new Application::Private();
    }

    Application::~Application() {
        delete m_impl;
    }

    PluginManager* Application::getPluginManager() {
        assert(m_impl);

        return &m_impl->m_pluginManager;
    }
}
