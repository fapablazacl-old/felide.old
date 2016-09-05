
#include "PluginWin.hpp"

#include <felide/Application.hpp>

namespace felide {

    PluginWin::PluginWin() {}

    PluginWin::~PluginWin() {}

    PluginData PluginWin::getData() const {
        return {
            "WinAPI UI", 
            "User interface implemented using the Windows API for maximun performance and customization on Windows(R) platforms."
        };
    }

    void PluginWin::start(Application *application) {
        application->setViewFactory(&m_viewFactory);
    }

    void PluginWin::stop(Application *application) {
        application->setViewFactory(nullptr);
    }
}

extern "C" {
    FELIDE_CORE_API_EXPORT felide::Plugin* felide_createPlugin() {
        return new felide::PluginWin();
    }
}
