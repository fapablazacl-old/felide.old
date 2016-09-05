
set (target felide.windows)

set (sources 
    "felide/PluginWin.cpp" 
    "felide/PluginWin.hpp" 
    "felide/ViewFactoryWin.cpp"
    "felide/ViewFactoryWin.hpp"
    "felide/MainFrameWin.cpp" 
    "felide/MainFrameWin.hpp" 
    "felide/PluginFrameWin.cpp" 
    "felide/PluginFrameWin.hpp" 
)

source_group (\\ FILES ${sources})

add_library (${target} SHARED ${sources})

target_link_libraries (${target} felide.core)
