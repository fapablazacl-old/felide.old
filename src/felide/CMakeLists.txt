
project (felide)

# link_directories(/usr/lib64/qt4/)
# find_package(QScintilla REQUIRED)

set (felide_sources_cpp 
    model/Source.cpp 
    model/util/Util.cpp
)

set (felide_sources_qt
    Main.cpp 
    view/MainWindow.cpp 
    model/Source.hpp 
    model/util/Util.hpp
)

set (felide_headers_qt
    view/MainWindow.hpp
)

QT4_WRAP_CPP(felide_headers_moc ${felide_headers_qt})

add_executable(felide ${felide_sources_qt} ${felide_sources_cpp} ${felide_headers_moc})
target_link_libraries(felide ${QT_LIBRARIES} ${QSCINTILLA_LIBRARY}) 
