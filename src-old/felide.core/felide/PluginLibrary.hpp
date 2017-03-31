
#ifndef __felide_core_pluginlibrary_hpp__
#define __felide_core_pluginlibrary_hpp__

#include <string>
#include <memory>

#include <felide/Library.hpp>

#include "Plugin.hpp"

namespace felide { 
    
    class PluginLibrary : public Plugin {
    public:
        explicit PluginLibrary(std::unique_ptr<Library> library);

        virtual ~PluginLibrary();
        
        virtual PluginData getData() const override {
            return m_plugin->getData();
        }

        virtual void start(Application *application) override {
            m_plugin->start(application);
        }

        virtual void stop(Application *application) override {
            m_plugin->stop(application);
        }

    private:
        std::unique_ptr<Library> m_library;
        std::unique_ptr<Plugin> m_plugin;
    };
}

#endif 
