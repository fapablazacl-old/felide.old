
#include "PluginLibrary.hpp"

namespace felide {
    PluginLibrary::PluginLibrary(std::unique_ptr<Library> library) {
        m_library = std::move(library);

        auto createPluginAddress = m_library->getAddress("felide_createPlugin");
        auto createPlugin = (Plugin* (*)()) createPluginAddress;

        m_plugin = std::unique_ptr<Plugin>(createPlugin());
    }

    PluginLibrary::~PluginLibrary() {}
}
