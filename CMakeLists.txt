
project(felide)

cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


# Other
add_definitions(-std=c++11)

include_directories(src)

add_subdirectory(src)
