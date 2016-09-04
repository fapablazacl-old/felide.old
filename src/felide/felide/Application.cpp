
#include "Application.hpp"

#include <cassert>
#include <felide/core/PluginManagerImpl.hpp>

namespace felide {  namespace core {
    struct Application::Private {
        std::unique_ptr<PluginManager> pluginManager;
        std::unique_ptr<felide::core::SystemFactory> systemFactory;

        felide::core::view::ViewFactory* viewFactory = nullptr;
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

    felide::core::view::ViewFactory* Application::getViewFactory() {
        assert(m_impl);
        if (!m_impl->viewFactory) {
            throw std::runtime_error("felide::Application::getViewFactory: 'nullptr'");
        }

        return m_impl->viewFactory;
    }

    void Application::setViewFactory(felide::core::view::ViewFactory* viewFactory) {
        assert(m_impl);
        m_impl->viewFactory = viewFactory;
    }
}}
