
#pragma once

#ifndef __felide_application_hpp__
#define __felide_application_hpp__

namespace felide {
    class PluginManager;

    class Application {
    public:
        Application();
        ~Application();

        PluginManager* getPluginManager();

    private:
        struct Private;
        Private *m_impl = nullptr;
    };
}

#endif 
