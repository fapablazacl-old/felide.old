
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Qt4 REQUIRED)
# find_package(QScintilla REQUIRED)

include(${QT_USE_FILE})

add_definitions(${QT_DEFINITIONS})
add_definitions(-std=c++11)

include_directories(src)

add_subdirectory(src)
