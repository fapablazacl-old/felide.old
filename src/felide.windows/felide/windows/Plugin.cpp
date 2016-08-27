
#include "Plugin.hpp"

#include <felide/core/Application.hpp>

namespace felide { namespace windows {

    Plugin::Plugin() {}

    Plugin::~Plugin() {}

    felide::core::PluginData Plugin::getData() const {
        return {
            "WinAPI UI", 
            "User interface implemented using the Windows API for maximun performance and customization on Windows(R) platforms."
        };
    }

    void Plugin::start(felide::core::Application *application) {
        application->setViewFactory(&m_viewFactory);
    }

    void Plugin::stop(felide::core::Application *application) {
        application->setViewFactory(nullptr);
    }
}}

extern "C" {
    FELIDE_CORE_API_EXPORT felide::core::Plugin* felide_createPlugin() {
        return new felide::windows::Plugin();
    }
}
