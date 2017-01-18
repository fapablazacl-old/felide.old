
set (target core)

set (sources 
	felide/Application.hpp
	felide/Application.cpp
	felide/Plugin.hpp
	felide/Plugin.cpp
	felide/PluginManager.hpp
	felide/PluginManager.cpp
)

source_group(\\ FILES ${sources})

add_library(${target} ${sources})
