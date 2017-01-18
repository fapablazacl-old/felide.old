
set (target felide-win)
set (sources 
	felide/WinApplication.hpp
	felide/WinApplication.cpp
)

source_group(\\ FILES ${sources})

add_executable(${target} WIN32 ${sources})

target_link_libraries(${target} core)
