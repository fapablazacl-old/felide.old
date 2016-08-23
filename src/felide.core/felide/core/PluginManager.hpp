
#ifndef __felide_core_pluginmanager_hpp__
#define __felide_core_pluginmanager_hpp__

#include <string>

namespace felide {  namespace core {
    class Application;
    class Locator;
    class PluginManager {
    public:
        virtual ~PluginManager();

        virtual Application* getApplication() = 0;

        virtual Locator* getLocator() = 0;

        virtual void load(const std::string &name) = 0;

        virtual void unload(const std::string &name) = 0;
    };
}}

#endif 
