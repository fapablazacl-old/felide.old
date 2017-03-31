
set (target felide-borc)
set (sources "felide/Borc.cpp")

add_executable(${target} ${sources})

source_group(\\felide FILES ${sources})

target_link_libraries(${target} ${Boost_LIBRARIES} libborc)
