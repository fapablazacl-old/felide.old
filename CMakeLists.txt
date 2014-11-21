cmake_minimum_required(VERSION 2.8)

project (felide)

link_directories(/usr/lib64/qt4/)

include_directories(src)

find_package(Qt4 REQUIRED)
# find_package(QScintilla REQUIRED)

set(felide_sources_cpp src/felide/model/Source.cpp)
set(felide_sources src/felide/Main.cpp src/felide/view/MainWindow.cpp src/felide/model/Source.hpp)
set(felide_headers src/felide/view/MainWindow.hpp)

QT4_WRAP_CPP(felide_headers_moc ${felide_headers})

include(${QT_USE_FILE})

add_definitions(${QT_DEFINITIONS})
add_definitions(-std=c++11)

add_executable(felide ${felide_sources} ${felide_sources_cpp} ${felide_headers_moc})

target_link_libraries(felide ${QT_LIBRARIES} qscintilla2)
