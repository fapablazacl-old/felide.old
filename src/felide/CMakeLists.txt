
#if (FELIDE_GEN_WIN32)

#    # Force the C++ compiler to use UNICODE instead of ANSI
#    add_definitions(-DUNICODE)
#    add_definitions(-D_UNICODE)

#    # disable those annoying Visual C++ warnings about deprecation..
#    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

#    # WCL
#    if (NOT WCL_INCLUDE_DIRS)
#        MESSAGE (ERROR_MESSAGE "WCL include location isn't defined. Please define the WCL_INCLUDE_DIRS variable.")
#        set (WCL_FOUND 0)
#        set (WCL_LIBRARIES )
#    else()
#        set (WCL_FOUND 1)
#        set (WCL_LIBRARIES comctl32)
#    endif ()

#    if (NOT SCINTILLA_INCLUDE_DIRS)
#        MESSAGE (ERROR_MESSAGE "Scintilla include location isn't defined (-DSCINTILLA_INCLUDE_DIRS).")
#        set (SCINTILLA_FOUND 0)
#        set (SCINTILLA_LIBRARIES)
#    else()
#        set (SCINTILLA_FOUND 1)
#        set (SCINTILLA_LIBRARIES)
#    endif ()
    
#    include_directories(${WCL_INCLUDE_DIRS})
#    include_directories(${SCINTILLA_INCLUDE_DIRS})

#    set (FELIDE_VIEW_WIN32_LIBRARIES comctl32)

#    set (felide_view_win32_src
#            view/win/WAppImpl.hpp
#            view/win/WAppImpl.cpp
#            view/win/WMainFrame.cpp 
#            view/win/WMainFrame.hpp 
#            view/win/WMainFrame.ui.cpp 
#            view/win/WDialogFactory.cpp 
#            view/win/WDialogFactory.hpp 
#            view/win/WEditor.cpp 
#            view/win/WEditor.hpp 
#    )
    
#    add_definitions(-DFELIDE_VIEW_WIN32)
#endif()


set(felide_src
    Config.hpp
    ProjectItem.hpp 
    ProjectItem.cpp
    Project.hpp 
    Project.cpp
    Workspace.hpp 
    Workspace.cpp
    Toolchain.hpp 
    Toolchain.cpp
    App.hpp 
    App.cpp
    LexerConstants.cpp 
    LexerConstants.hpp 
    felide.cpp
)

set(felide_system_src
    system/Environment.hpp 
    system/Environment.cpp
    system/Module.hpp 
    system/Module.cpp
    system/Process.hpp 
    system/ProcessWin32.cpp
    system/ProcessUnix.cpp
    system/Library.hpp 
    system/Library.cpp
)

set (felide_view_src
    view/Editor.hpp
    view/Editor.cpp
    view/View.hpp
    view/View.cpp
    view/Dialog.hpp
    view/Dialog.cpp
    view/DialogFactory.hpp
    view/DialogFactory.cpp
    view/MainFrame.hpp
    view/MainFrame.cpp
    view/MainFrameHandler.hpp
    view/MainFrameHandler.cpp
)


add_executable(felide 
    ${felide_src} 
    ${felide_system_src} 
    ${felide_view_src} 
)

source_group(\\             FILES ${felide_src})
source_group(\\system       FILES ${felide_system_src})
source_group(\\view         FILES ${felide_view_src})
source_group(\\view\\qt5    FILES ${felide_view_qt5_src})
source_group(\\view\\wcl    FILES ${felide_view_win32_src})

target_link_libraries(felide ${Boost_LIBRARIES} ${FELIDE_QT5_LIBRARIES} ${FELIDE_WIN32_LIBRARIES})

install(TARGETS felide DESTINATION ".")
