
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

set (src_felide_model
	model/Source.hpp 					model/Source.cpp 
	model/ProjectItem.hpp				model/ProjectItem.cpp 
	model/Project.hpp					model/Project.cpp 
	model/Workspace.hpp					model/Workspace.cpp 
	model/WorkspaceManager.hpp			model/WorkspaceManager.cpp 
	model/WorkspaceManager.hpp			model/WorkspaceManager.cpp
	model/FelideWorkspaceManager.hpp	model/FelideWorkspaceManager.cpp
)

set (src_felide_model_util
	model/util/Util.hpp		model/util/Util.cpp
)

set (src_felide_view
	view/MainWindow.hpp                 view/MainWindow.cpp 
    view/SourceEditor.hpp               view/SourceEditor.cpp
	view/SourceEditorGeneric.hpp        view/SourceEditorGeneric.cpp
	view/SourceEditorScintilla.hpp      view/SourceEditorScintilla.cpp
)

set (src_felide
    Main.cpp 
)

source_group (\\ FILES ${src_felide})
source_group (model FILES ${src_felide_model})
source_group (model\\util FILES ${src_felide_model_util})
source_group (view FILES ${src_felide_view})

add_executable(felide ${src_felide} ${src_felide_model} ${src_felide_model_util} ${src_felide_view})

target_link_libraries(felide ${Boost_LIBRARIES} Qt5::Widgets)

# Installation
install (TARGETS felide DESTINATION bin)
