
set (target felide2)
set (sources 
    felide/felide2.cpp

    felide/FelideApp.hpp
    felide/FelideApp.cpp

    felide/MainFrameHandler.hpp
    felide/MainFrameHandler.cpp
)

add_executable(${target} ${sources})

source_group(\\ FILES ${sources})

target_link_libraries(${target} felide.core)
