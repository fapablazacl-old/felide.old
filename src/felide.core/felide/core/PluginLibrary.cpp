
#include "PluginLibrary.hpp"

namespace felide {  namespace core {
    PluginLibrary::PluginLibrary(std::unique_ptr<felide::system::Library> library) {
        m_library = std::move(library);

        auto createPluginAddress = m_library->getAddress("felide_createPlugin");
        auto createPlugin = (std::unique_ptr<Plugin> (*)()) createPluginAddress;

        m_plugin = createPlugin();
    }

    PluginLibrary::~PluginLibrary() {
    
    }
}}
