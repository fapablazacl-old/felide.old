
set (target felide.windows)

set (sources 
    "felide/MainFrameWin.cpp" 
    "felide/MainFrameWin.hpp" 
    "felide/PluginWin.cpp" 
    "felide/PluginWin.hpp" 
    "felide/ViewFactoryWin.cpp"
    "felide/ViewFactoryWin.hpp"
)

source_group (\\ FILES ${sources})

add_library (${target} SHARED ${sources})

target_link_libraries (${target} felide.core)
