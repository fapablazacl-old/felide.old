
set (target felide.core)

set (sources 
    "felide/core/Application.cpp" 
    "felide/core/Application.hpp" 
    "felide/core/Plugin.cpp" 
    "felide/core/Plugin.hpp" 
    "felide/core/PluginLibrary.cpp" 
    "felide/core/PluginLibrary.hpp" 
    "felide/core/PluginManager.cpp" 
    "felide/core/PluginManager.hpp" 
    "felide/core/PluginManagerImpl.cpp" 
    "felide/core/PluginManagerImpl.hpp" 
    "felide/core/Locator.cpp" 
    "felide/core/Locator.hpp" 
    "felide/core/PathEnvLocator.cpp" 
    "felide/core/PathEnvLocator.hpp" 
    "felide/core/ArbitraryLocator.cpp" 
    "felide/core/ArbitraryLocator.hpp" 
)

source_group(\\ FILES ${sources})

add_library (${target} SHARED ${sources})
target_link_libraries (${target} ${Boost_LIBRARIES} felide.system)
