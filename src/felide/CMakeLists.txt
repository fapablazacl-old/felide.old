
IF (CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") 
ENDIF()

SET(Boost_USE_STATIC_LIBS OFF) 
SET(Boost_USE_STATIC_RUNTIME OFF) 
SET(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost REQUIRED )

IF (WIN32)
	ADD_DEFINITIONS( -D__WXMSW__ )
	ADD_DEFINITIONS( -D_UNICODE )
	ADD_DEFINITIONS( -DWXUSINGDLL )

	SET (wxWidgets_ROOT_DIR $ENV{wxWidgets_ROOT_DIR})

	IF(CMAKE_BUILD_TYPE MATCHES DEBUG) 
		SET (DEBUG_POSTFIX "d")
	ELSE()
		SET (DEBUG_POSTFIX "")
	ENDIF()
	
	IF (MSVC)
		SET (COMPILER vc_dll)
	ELSE()
		SET (COMPILER gcc_dll)
	ENDIF()
	
	SET (wxWidgets_INCLUDE_DIRS 
		${wxWidgets_ROOT_DIR}/include 
		${wxWidgets_ROOT_DIR}/lib/${COMPILER}/mswu${DEBUG_POSTFIX}
	)
	
	SET (wxWidgets_LINK_DIRS ${wxWidgets_ROOT_DIR}/lib/${COMPILER})
	SET (wxWidgets_LIBS wxbase30u${DEBUG_POSTFIX} wxmsw30u${DEBUG_POSTFIX}_core)
ELSE()
	FIND_PACKAGE(wxWidgets REQUIRED)
ENDIF()

INCLUDE_DIRECTORIES(felide .. ${Boost_INCLUDE_DIRS} ${wxWidgets_INCLUDE_DIRS})

SET (MainSources Main.cpp)
SET (InterfaceSources 
	interface/EditorWidget.hpp			interface/EditorWidget.cpp
	interface/EditorWidgetManager.hpp	interface/EditorWidgetManager.cpp
	interface/MainWindow.hpp			interface/MainWindow.cpp	
	interface/ProjectDockWidget.hpp		interface/ProjectDockWidget.cpp
)

SET (ProjectsSources 
	projects/Builder.hpp		projects/Builder.cpp
    projects/ProjectItem.hpp	projects/ProjectItem.cpp
    projects/Project.hpp		projects/Project.cpp
	projects/Workspace.hpp		projects/Workspace.cpp
)

SET (SystemSources 
	system/Environment.hpp	system/Environment.cpp
    system/Module.hpp		system/Module.cpp
	system/Process.hpp		system/Process.cpp
	system/Library.hpp		system/Library.cpp
)

SET (ToolchainsSources 
	toolchains/Compiler.hpp		toolchains/Compiler.cpp
    toolchains/Linker.hpp		toolchains/Linker.cpp
    toolchains/Runtime.hpp		toolchains/Runtime.cpp
    toolchains/Toolchain.hpp	toolchains/Toolchain.cpp
)

SET (UtilSources
	util/FileUtil.hpp			util/FileUtil.cpp
)

SOURCE_GROUP(Main		FILES ${MainSources} )
SOURCE_GROUP(Interface	FILES ${InterfaceSources} )
SOURCE_GROUP(Projects	FILES ${ProjectsSources} )
SOURCE_GROUP(System		FILES ${SystemSources} )
SOURCE_GROUP(Toolchains FILES ${ToolchainsSources} )
SOURCE_GROUP(Util		FILES ${UtilSources} )

LINK_DIRECTORIES(${wxWidgets_LINK_DIRS})

ADD_EXECUTABLE(felide WIN32 ${MainSources} ${InterfaceSources} ${ProjectsSources} ${SystemSources} ${ToolchainsSources} ${UtilSources})

TARGET_LINK_LIBRARIES(felide ${wxWidgets_LIBS})
