
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions("-fPIC")
endif ()

set (target felide.qt5)

set (sources
    AppImpl.hpp AppImpl.cpp
    DialogFactoryImpl.hpp DialogFactoryImpl.cpp
    EditorImpl.hpp EditorImpl.cpp
    MainFrameImpl.hpp MainFrameImpl.cpp
    
    TabbedEditor.hpp TabbedEditor.cpp
    MainPanel.hpp MainPanel.cpp
    WorkspaceView.hpp WorkspaceView.cpp
    WorkspaceModel.hpp WorkspaceModel.cpp
    OutputWindow.hpp OutputWindow.cpp
)

add_library(${target} ${sources})
