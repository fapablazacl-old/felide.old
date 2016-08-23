
#include "Application.hpp"
#include "PluginManagerImpl.hpp"

namespace felide {  namespace core {
    Application::Application() {
        m_pluginManager.reset(new PluginManagerImpl(this));
    }

    Application::~Application() {
    
    }
}}
