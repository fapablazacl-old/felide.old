
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
	felide/ResourceManagerImpl.hpp
	felide/ResourceManagerImpl.cpp
	felide/Project.hpp
	felide/Project.cpp
	felide/Target.hpp
	felide/Target.cpp
	felide/Item.hpp
	felide/Item.cpp
	felide/FileUtil.hpp
	felide/FileUtil.cpp
	felide/Menu.hpp
	felide/Menu.cpp
)

source_group(\\ FILES ${sources})

add_library(${target} ${sources})
