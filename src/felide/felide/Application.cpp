
#include "Application.hpp"

#include <cassert>
#include <felide/PluginManagerImpl.hpp>

namespace felide { 
    struct Application::Private {
        std::unique_ptr<PluginManager> pluginManager;
        std::unique_ptr<SystemFactory> systemFactory;

        ViewFactory* viewFactory = nullptr;
    };

    Application::Application()  {
        m_impl = new Application::Private();

        m_impl->pluginManager.reset(new PluginManagerImpl(this));
        m_impl->systemFactory = SystemFactory::newInstance();
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

    SystemFactory* Application::getSystemFactory() {
        assert(m_impl);
        return m_impl->systemFactory.get();
    }

    ViewFactory* Application::getViewFactory() {
        assert(m_impl);
        if (!m_impl->viewFactory) {
            throw std::runtime_error("felide::Application::getViewFactory: 'nullptr'");
        }

        return m_impl->viewFactory;
    }

    void Application::setViewFactory(ViewFactory* viewFactory) {
        assert(m_impl);
        m_impl->viewFactory = viewFactory;
    }
}
