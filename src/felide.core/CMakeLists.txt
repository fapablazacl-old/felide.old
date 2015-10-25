
SET(felide_src
	felide/Config.hpp
	felide/Common.hpp
	felide/ProjectItem.hpp 
    felide/ProjectItem.cpp
	felide/Project.hpp 
    felide/Project.cpp
	felide/Workspace.hpp 
    felide/Workspace.cpp
	felide/Toolchain.hpp 
    felide/Toolchain.cpp
	felide/Application.hpp 
    felide/Application.cpp
)

SET(felide_system_src
	felide/system/Environment.hpp 
    felide/system/Environment.cpp
	felide/system/Module.hpp 
    felide/system/Module.cpp
	felide/system/Process.hpp 
    felide/system/ProcessWin32.cpp
    felide/system/ProcessUnix.cpp
	felide/system/Library.hpp 
    felide/system/Library.cpp
)

SET (felide_view_src
	felide/view/Editor.hpp
	felide/view/Editor.cpp
	felide/view/View.hpp
	felide/view/View.cpp
	felide/view/Handler.hpp
	felide/view/Handler.cpp
    felide/view/Dialog.hpp
    felide/view/Dialog.cpp
	felide/view/DialogFactory.hpp
	felide/view/DialogFactory.cpp
)

ADD_DEFINITIONS(-DFELIDE_BUILD)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ADD_LIBRARY(felide.core ${felide_src} ${felide_system_src} ${felide_view_src})
SET_PROPERTY(TARGET felide.core PROPERTY CXX_STANDARD 14)
SOURCE_GROUP(\\         FILES ${felide_src})
SOURCE_GROUP(\\system   FILES ${felide_system_src})
SOURCE_GROUP(\\view     FILES ${felide_view_src})

TARGET_LINK_LIBRARIES(felide.core ${Boost_LIBRARIES})
