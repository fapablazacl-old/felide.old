

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


IF(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") 
ENDIF()

SET(Boost_USE_STATIC_LIBS OFF) 
SET(Boost_USE_STATIC_RUNTIME OFF) 
SET(Boost_USE_MULTITHREADED ON)

FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)

INCLUDE_DIRECTORIES(felide .. ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(MainSources Main.cpp)

set(InterfaceUiSources
    interface/MainWindow.ui
)

SET(InterfaceHeadersMOC 
	interface/EditorWidget.hpp
	interface/EditorWidgetManager.hpp
	interface/MainWindow.hpp
	interface/ProjectDockWidget.hpp
)

SET(InterfaceSources ${InterfaceHeadersMOC}
	interface/EditorWidget.hpp			interface/EditorWidget.cpp
	interface/EditorWidgetManager.hpp	interface/EditorWidgetManager.cpp
	interface/MainWindow.hpp			interface/MainWindow.cpp	
	interface/ProjectDockWidget.hpp		interface/ProjectDockWidget.cpp
)

SET(ProjectsSources 
	projects/Builder.hpp		projects/Builder.cpp
    projects/ProjectItem.hpp	projects/ProjectItem.cpp
    projects/Project.hpp		projects/Project.cpp
	projects/Workspace.hpp		projects/Workspace.cpp
    projects/Manager.hpp		projects/Manager.cpp
)

SET(SystemSources 
	system/Environment.hpp	system/Environment.cpp
    system/Module.hpp		system/Module.cpp
	system/Process.hpp		system/Process.cpp
	system/Library.hpp		system/Library.cpp
)

SET(ToolchainsSources 
	toolchains/Compiler.hpp		toolchains/Compiler.cpp
    toolchains/Linker.hpp		toolchains/Linker.cpp
    toolchains/Runtime.hpp		toolchains/Runtime.cpp
    toolchains/Toolchain.hpp	toolchains/Toolchain.cpp
)

SET(UtilSources
	util/FileUtil.hpp			util/FileUtil.cpp
)

SOURCE_GROUP(Main		FILES ${MainSources} )
SOURCE_GROUP(Interface	FILES ${InterfaceSources} )
SOURCE_GROUP(Projects	FILES ${ProjectsSources} )
SOURCE_GROUP(System		FILES ${SystemSources} )
SOURCE_GROUP(Toolchains FILES ${ToolchainsSources} )
SOURCE_GROUP(Util		FILES ${UtilSources} )

QT5_WRAP_UI(InterfaceUiSourcesMOC ${InterfaceUiSources})

ADD_EXECUTABLE(felide WIN32 
    ${MainSources} 
    ${InterfaceUiSourcesMOC}
    ${InterfaceSourcesMOC} 
    ${InterfaceSources} 
    ${ProjectsSources} 
    ${SystemSources} 
    ${ToolchainsSources} 
    ${UtilSources}
)

TARGET_LINK_LIBRARIES(felide Qt5::Widgets)
