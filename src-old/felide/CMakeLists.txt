
set (target felide)
set (sources 
    "felide/PreDef.cpp" 
    "felide/PreDef.hpp" 
    "felide/felide.cpp"
    "felide/FelideApp.hpp"
    "felide/FelideApp.cpp"
    "felide/MainFrameHandler.hpp"
    "felide/MainFrameHandler.cpp"
)

add_executable(${target} ${sources})

source_group(\\ FILES ${sources})

target_link_libraries(${target} felide.core felide.view)
