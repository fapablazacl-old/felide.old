
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set (target felide-win)
set (sources 
	felide/WinApplication.hpp
	felide/WinApplication.cpp
	felide/WinMainFrame.hpp
	felide/WinMainFrame.cpp
)

source_group(\\ FILES ${sources})

add_executable(${target} WIN32 ${sources})

target_link_libraries(${target} core)
