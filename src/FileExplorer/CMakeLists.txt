
set (FileExplorer_sources TreeItem.hpp TreeItem.cpp)

set (FileExplorer_sources_qt
    FileExplorer.cpp
    TreeModel.cpp
)

set (FileExplorer_headers_qt
    FileExplorer.hpp
    TreeModel.hpp
)

QT4_WRAP_CPP(FileExplorer_headers_moc ${FileExplorer_headers_qt})

add_executable(FileExplorer 
    ${FileExplorer_sources} 
    ${FileExplorer_sources_qt} 
    ${FileExplorer_headers_moc}
)

target_link_libraries(FileExplorer ${QT_LIBRARIES})
