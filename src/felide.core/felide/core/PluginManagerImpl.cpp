
#include "PluginManagerImpl.hpp"

#include <cstdlib>

namespace felide {  namespace core {
    PluginManagerImpl::PluginManagerImpl(Application* application) 
        : m_application(application) {

    }

    PluginManagerImpl::~PluginManagerImpl() {}

    void PluginManagerImpl::load(const std::string &name) {
    
        
    }

    void PluginManagerImpl::unload(const std::string &name) {
        
    }
}}
