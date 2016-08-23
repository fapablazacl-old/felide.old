
set (target felide.core)

set (sources 
    "felide/core/Application.cpp" 
    "felide/core/Application.hpp" 
    "felide/core/Plugin.cpp" 
    "felide/core/Plugin.hpp" 
    "felide/core/PluginManager.cpp" 
    "felide/core/PluginManager.hpp" 
    "felide/core/Locator.cpp" 
    "felide/core/Locator.hpp" 
)

source_group(\\ FILES ${sources})

add_library (${target} SHARED ${sources})
