
set (target felide2)
set (sources 
    felide/felide2.cpp

    felide/Resources.hpp
    felide/Resources.cpp
)

add_executable(${target} ${sources})

source_group(\\ FILES ${sources})

target_link_libraries(${target} felide.core)
