
#pragma once

#ifndef __felide_application_hpp__
#define __felide_application_hpp__

#include <vector>
#include <string>

namespace felide {
    class PluginManager;
    class ResourceManager;

    class Application {
    public:
        Application();
        ~Application();

        PluginManager* getPluginManager();

        const ResourceManager* getResourceManager();

    private:
        struct Private;
        Private *m_impl = nullptr;
    };
}

#endif 
