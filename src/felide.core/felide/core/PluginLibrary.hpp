
#ifndef __felide_core_pluginlibrary_hpp__
#define __felide_core_pluginlibrary_hpp__

#include <string>
#include <memory>

#include "Plugin.hpp"
#include "felide/system/Library.hpp"

namespace felide {  namespace core {
    
    class PluginLibrary : public Plugin {
    public:
        explicit PluginLibrary(std::unique_ptr<felide::system::Library> library);

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
        std::unique_ptr<felide::system::Library> m_library;
        std::unique_ptr<felide::core::Plugin> m_plugin;
    };
}}

#endif 
