
#include "PluginManagerImpl.hpp"

#include "ArbitraryLocator.hpp"

#include <cstdlib>

namespace felide {  namespace core {
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

    }

    void PluginManagerImpl::unload(const std::string &name) {
        
    }
}}
