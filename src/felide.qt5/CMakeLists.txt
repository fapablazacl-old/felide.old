
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
)

QT5_WRAP_UI (felide_view_qt5_ui
    MainFrame.ui
)

add_library(${target} ${sources})
