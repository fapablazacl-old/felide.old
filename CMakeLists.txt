
cmake_minimum_required(VERSION 3.0)

project (felide)

# Supported User Interface APIs
set (FELIDE_UI_API "Qt5" CACHE STRING "User Interface API")
#set (FELIDE_UI_APIS "Qt5;WinAPI")
set (FELIDE_UI_APIS "Qt5")

set_property(CACHE FELIDE_UI_API PROPERTY STRINGS ${FELIDE_UI_APIS})

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Boost
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS
    system
    filesystem
    program_options
)

# YAML
# find_package(yaml-cpp REQUIRED)

# Include dirs
include_directories (${Boost_INCLUDE_DIRS})

# Targets
include_directories (sources/libcore)
add_subdirectory (sources/libcore)

include_directories (sources/libborc)
add_subdirectory (sources/libborc)

include_directories (sources/felide-borc)
add_subdirectory (sources/felide-borc)

if (${FELIDE_UI_API} MATCHES Qt5)
	add_subdirectory(sources/felide-qt5)
endif()
