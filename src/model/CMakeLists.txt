
set (target model)

set (sources 
	model.cpp
)

add_executable (${target} ${sources})

target_link_libraries (${target} ${Boost_LIBRARIES})
