
#ifndef __felide_core_plugin_hpp__
#define __felide_core_plugin_hpp__

#include <string>

namespace felide {  namespace core {
    struct PluginData {
        std::string name;
        std::string desc;
    };

    class Application;
    class Plugin {
    public:
        virtual ~Plugin();
        
        virtual PluginData getData() const = 0;

        virtual void start(Application *application) = 0;

        virtual void stop(Application *application) = 0;
    };
}}

#endif 
