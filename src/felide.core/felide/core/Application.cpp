
#include "Application.hpp"
#include "PluginManagerImpl.hpp"

#include <cassert>

namespace felide {  namespace core {
    struct Application::Private {
        std::unique_ptr<PluginManager> pluginManager;
        std::unique_ptr<felide::core::SystemFactory> systemFactory;
    };

    Application::Application()  {
        m_impl = new Application::Private();

        m_impl->pluginManager.reset(new PluginManagerImpl(this));
        m_impl->systemFactory = felide::core::SystemFactory::newInstance();
    }

    Application::~Application() {
        if (m_impl) {
            delete m_impl;
        }
    }

    PluginManager* Application::getPluginManager() {
        assert(m_impl);
        return m_impl->pluginManager.get();
    }

    felide::core::SystemFactory* Application::getSystemFactory() {
        assert(m_impl);
        return m_impl->systemFactory.get();
    }
}}
