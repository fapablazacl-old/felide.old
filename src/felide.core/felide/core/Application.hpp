
#ifndef __felide_core_application_hpp__
#define __felide_core_application_hpp__

#include "PluginManager.hpp"

namespace felide {  namespace core {
    class Application {
    public:
        Application();
        virtual ~Application();

        PluginManager* getPluginManager() {
            return &m_pluginManager;
        }

    private:
        PluginManager m_pluginManager;
    };
}}

#endif 
