
cmake_minimum_required(VERSION 3.0)

project (felide)

option (FELIDE_GEN_QT5     "Enable QT5 based user interface"       OFF)
option (FELIDE_GEN_WCL     "Enable WinAPI-based user interface"    OFF)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake)

# Boost
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

find_package (Boost 1.59.0 COMPONENTS filesystem system REQUIRED)

# Include dirs
include_directories (${Boost_INCLUDE_DIRS})
include_directories (src)

if (FELIDE_GEN_QT5)
    set (CMAKE_AUTOUIC ON)
    set (CMAKE_INCLUDE_CURRENT_DIR ON)
    set (CMAKE_AUTOMOC ON)
    
    find_package(Qt5Widgets REQUIRED)
    find_package(QScintilla REQUIRED)
    
    add_definitions(-DQSCINTILLA_DLL)

    set (FELIDE_QT5_LIBRARIES felide.qt5 Qt5::Widgets ${QSCINTILLA_LIBRARY})
    
    include_directories(${QSCINTILLA_INCLUDE_DIR})
    include_directories(${Qt5Widgets_INCLUDE_DIRS})
    
    add_subdirectory (src/felide.qt5)
endif()

if (FELIDE_GEN_WCL)
    # WCL
    set (WCL_LIBRARIES comctl32)

    set (SCINTILLA_FOUND 0)
    set (SCINTILLA_LIBRARIES)

    if (NOT SCINTILLA_INCLUDE_DIRS)
        message (ERROR_MESSAGE "Scintilla include location isn't defined (-DSCINTILLA_INCLUDE_DIRS).")
        set (SCINTILLA_FOUND 0)
        set (SCINTILLA_LIBRARIES)
    endif ()
    
    set (FELIDE_WCL_LIBRARIES felide.wcl comctl32)

    include_directories(${SCINTILLA_INCLUDE_DIRS})

    add_subdirectory (src/wcl)
    add_subdirectory (src/wclc)
    add_subdirectory (src/felide.wcl)
endif ()

add_subdirectory (src/pom)
add_subdirectory (src/felide.proj.cmake)
add_subdirectory (src/felide.proj.impl)

add_subdirectory (src/felide)
add_subdirectory (src/model)
