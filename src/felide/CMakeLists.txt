
SET(felide_src 
	 ProjectItem.hpp ProjectItem.cpp
	 Project.hpp Project.cpp
	 Workspace.hpp Workspace.cpp
	 Toolchain.hpp Toolchain.cpp
)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ADD_LIBRARY(felide ${felide_src})
SET_PROPERTY(TARGET felide PROPERTY CXX_STANDARD 11)
SOURCE_GROUP(\\ FILES ${felide_src})
TARGET_LINK_LIBRARIES(felide ${Boost_LIBRARIES})
