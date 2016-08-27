
set (target felide.windows)

set (sources 
    "felide/windows/MainFrame.cpp" 
    "felide/windows/MainFrame.hpp" 
    "felide/windows/Plugin.cpp" 
    "felide/windows/Plugin.hpp" 
)

source_group(\\ FILES ${sources})

add_library(${target} ${sources})

target_link_libraries(${target} felide.core)
