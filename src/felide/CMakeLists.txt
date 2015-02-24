
project (felide)

link_directories(/usr/lib64/qt4/)

set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(${Boost_INCLUDE_DIRS})

set (felide_sources_cpp 
    model/Source.cpp 
    model/util/Util.cpp
)

set (felide_sources 
    Main.cpp 
    view/MainWindow.cpp 
    view/SourceEditor.cpp
    model/Source.hpp 
    model/util/Util.hpp
)

set (felide_headers 
    view/MainWindow.hpp
    view/SourceEditor.hpp
)

QT4_WRAP_CPP(felide_headers_moc ${felide_headers})

add_executable(felide ${felide_sources} ${felide_sources_cpp} ${felide_headers_moc})

target_link_libraries(felide ${Boost_LIBRARIES} ${QT_LIBRARIES} qscintilla2 )

# Installation
install (TARGETS felide DESTINATION bin)
