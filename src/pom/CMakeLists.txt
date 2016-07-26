
set (target pom)
set (sources pom.hpp pom.cpp)

add_executable (${target} ${sources})

target_link_libraries (${target} ${Boost_LIBRARIES})
