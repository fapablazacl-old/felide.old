
#include "Application.hpp"

#include <cassert>
#include <felide/PluginManagerImpl.hpp>

namespace felide { 
    struct Application::Private {
        std::unique_ptr<PluginManager> pluginManager;

        ViewFactory* viewFactory = nullptr;
    };

    Application::Application()  {
        m_impl = new Application::Private();

        m_impl->pluginManager.reset(new PluginManagerImpl(this));
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
