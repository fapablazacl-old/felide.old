
#ifndef __felwin_plugin_hpp__
#define __felwin_plugin_hpp__

#include <map>
#include <felide/core/Plugin.hpp>

#include "ViewFactory.hpp"

namespace felide { namespace windows {
    class Plugin : public felide::core::Plugin {
    public:
        Plugin();

        ~Plugin();

        virtual felide::core::PluginData getData() const override;

        virtual void start(felide::core::Application *application) override;

        virtual void stop(felide::core::Application *application) override;

    private:
        ViewFactory m_viewFactory;
    };
}}

#endif
