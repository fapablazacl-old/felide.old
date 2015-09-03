
SET(felide_src
	Config.hpp
	Common.hpp
	ProjectItem.hpp ProjectItem.cpp
	Project.hpp Project.cpp
	Workspace.hpp Workspace.cpp
	Toolchain.hpp Toolchain.cpp
)

SET(felide_system_src
	system/Environment.hpp system/Environment.cpp
	system/Module.hpp system/Module.cpp
	system/Process.hpp system/Process.cpp
	system/Library.hpp system/Library.cpp
)

ADD_DEFINITIONS(-DFELIDE_BUILD)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ADD_LIBRARY(felide SHARED ${felide_src} ${felide_system_src})
SET_PROPERTY(TARGET felide PROPERTY CXX_STANDARD 11)
SOURCE_GROUP(\\ FILES ${felide_src})
SOURCE_GROUP(\\system FILES ${felide_system_src})

TARGET_LINK_LIBRARIES(felide ${Boost_LIBRARIES})
