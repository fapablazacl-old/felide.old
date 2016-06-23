
cmake_minimum_required(VERSION 3.1)

project (felide)

option (FELIDE_GEN_QT5      "Enable QT5 based user interface"       OFF)
option (FELIDE_GEN_WIN32    "Enable WinAPI-based user interface"    OFF)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake)

# Boost
add_definitions(-DBOOST_ALL_NO_LIB)

set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

find_package (Boost COMPONENTS filesystem system REQUIRED)

# Include dirs
include_directories (${Boost_INCLUDE_DIRS})
include_directories (src)

add_subdirectory (src/felide)
