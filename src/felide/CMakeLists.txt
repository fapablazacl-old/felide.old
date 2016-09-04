
set (target felide)
set (sources 
    "felide/felide.cpp"
    "felide/FelideApp.hpp"
    "felide/FelideApp.cpp"
    "felide/Application.hpp"
    "felide/Application.cpp"
    "felide/MainFrameHandler.hpp"
    "felide/MainFrameHandler.cpp"
)

add_executable(${target} ${sources})

source_group(\\ FILES ${sources})

target_link_libraries(${target} felide.core felide.view)
