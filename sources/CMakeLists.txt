cmake_minimum_required(VERSION 3.1)

project(borc)

#Boost
find_package(Boost COMPONENTS
    system
    filesystem
    program_options
)

add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

include_directories(src/libborc)
include_directories(src/borc)

add_subdirectory(src/libborc)
add_subdirectory(src/borc)
