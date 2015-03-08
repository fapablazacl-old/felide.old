
# Qt5Widgets
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set (Qt_LIBRARY_PATH C:/Qt/5.4/msvc2013/lib)
link_directories(${Qt_LIBRARY_PATH})

# TODO: Make FindQScintilla happy
# set (QT_INCLUDE_DIR ${Qt5Widgets_INCLUDE_DIRS})
# message ( STATUS "QT_INCLUDE_DIR: " ${QT_INCLUDE_DIR})
# find_package(QScintilla REQUIRED)

# Boost
add_definitions(-DBOOST_ALL_NO_LIB)
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

link_directories(${Boost_LIBRARY_DIRS})

set (felide_src
    Main.cpp 
    
    model/Source.hpp 		model/Source.cpp 
    model/util/Util.hpp		model/util/Util.cpp
	view/MainWindow.hpp		view/MainWindow.cpp 
    view/SourceEditor.hpp	view/SourceEditor.cpp
)

add_executable(felide ${felide_src})

target_link_libraries(felide ${Boost_LIBRARIES} Qt5::Widgets qscintilla2)

# Installation
install (TARGETS felide DESTINATION bin)
