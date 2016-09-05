
set (target felide.core)

set (sources 
    "felide/Application.hpp"
    "felide/Application.cpp"
    "felide/RefCounted.cpp" 
    "felide/RefCounted.hpp" 
    "felide/Plugin.cpp" 
    "felide/Plugin.hpp" 
    "felide/PluginLibrary.cpp" 
    "felide/PluginLibrary.hpp" 
    "felide/PluginManager.cpp" 
    "felide/PluginManager.hpp" 
    "felide/PluginManagerImpl.cpp" 
    "felide/PluginManagerImpl.hpp" 
    "felide/Locator.cpp" 
    "felide/Locator.hpp" 
    "felide/PathEnvLocator.cpp" 
    "felide/PathEnvLocator.hpp" 
    "felide/ArbitraryLocator.cpp" 
    "felide/ArbitraryLocator.hpp" 
    "felide/FileUtil.cpp" 
    "felide/FileUtil.hpp" 
)

source_group(\\  FILES ${sources})

add_definitions(-DFELIDE_CORE_BUILD -DFELIDE_CORE_SHARED)
add_library (${target} SHARED ${sources})
target_link_libraries (${target} ${Boost_LIBRARIES} felide.system felide.view)
