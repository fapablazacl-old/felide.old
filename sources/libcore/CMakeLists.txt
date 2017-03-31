
set (target libcore)

set (sources 
	felide/Application.hpp
	felide/Application.cpp
	felide/Plugin.hpp
	felide/Plugin.cpp
	felide/PluginManager.hpp
	felide/PluginManager.cpp
	felide/Resource.hpp
	felide/Resource.cpp
	felide/ResourceManager.hpp
	felide/ResourceManager.cpp
	felide/Project.hpp
	felide/Project.cpp
	felide/Target.hpp
	felide/Target.cpp
	felide/Item.hpp
	felide/Item.cpp
)

source_group(\\ FILES ${sources})

add_library(${target} ${sources})
