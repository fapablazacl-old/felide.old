SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") 

# FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Qt4 REQUIRED)

INCLUDE_DIRECTORIES(felide ..)

SET(felide_QT_SOURCES 
    interface/MainWindow.cpp 
    interface/EditorWidget.cpp 
    interface/EditorWidgetManager.cpp 
    interface/ProjectDockWidget.cpp
)

SET(felide_QT_HEADERS 
    interface/MainWindow.hpp 
    interface/EditorWidget.hpp 
    interface/EditorWidgetManager.hpp 
    interface/ProjectDockWidget.hpp
)

QT4_WRAP_CPP(felide_QT_HEADERS_MOC ${felide_QT_HEADERS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(felide_SOURCES
    ${felide_QT_SOURCES} ${felide_QT_HEADERS_MOC}

    Main.cpp 

    projects/Builder.cpp
    projects/ProjectItem.cpp
    projects/Project.cpp
    projects/Workspace.cpp
    
    system/Environment.cpp
    system/Module.cpp
    system/Process.cpp
    system/Library.cpp
    
    toolchains/Compiler.cpp
    toolchains/Linker.cpp
    toolchains/Runtime.cpp
    toolchains/Toolchain.cpp
    
    util/FileUtil.cpp    
)

SET(felide_HEADERS
    ${felide_QT_HEADERS} 
    
    projects/Builder.hpp
    projects/ProjectItem.hpp
    projects/Project.hpp
    projects/Workspace.hpp
    
    system/Environment.hpp
    system/Module.hpp
    system/Process.hpp
    system/Library.hpp
    
    toolchains/Compiler.hpp
    toolchains/Linker.hpp
    toolchains/Runtime.hpp
    toolchains/Toolchain.hpp
    
    util/FileUtil.hpp
)

ADD_EXECUTABLE(felide ${felide_SOURCES} ${felide_HEADERS_MOC})

TARGET_LINK_LIBRARIES(felide ${QT_LIBRARIES})
