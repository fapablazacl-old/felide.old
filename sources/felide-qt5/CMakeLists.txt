
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

set (target felide-qt5)
set (sources 
	felide/MainWindow.hpp
	felide/MainWindow.cpp
	felide/MainPanel.hpp
	felide/MainPanel.cpp
	felide/ProjectBrowser.hpp
	felide/ProjectBrowser.cpp
	felide/ClassBrowser.hpp
	felide/ClassBrowser.cpp
	felide/DocumentManager.hpp
	felide/DocumentManager.cpp
	felide/QtApplication.hpp
	felide/QtApplication.cpp
)

find_package(Qt5Widgets)

source_group(\\ FILES ${sources})

add_executable(${target} WIN32 ${sources})

target_link_libraries(${target} ${Boost_LIBRARIES} libcore libborc Qt5::Widgets)
