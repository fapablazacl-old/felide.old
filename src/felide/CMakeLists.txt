
set(felide_src
    Predef.hpp 
    ProjectItem.hpp		
    ProjectItem.cpp
    Project.hpp			
    Project.cpp
    Workspace.hpp		
    Workspace.cpp
    Toolchain.hpp		
    Toolchain.cpp
    App.hpp				
    App.cpp
    LexerConstants.cpp	
    LexerConstants.hpp 
    Collection.hpp		
    Dictionary.hpp
    Lexer.hpp			
    Lexer.cpp
    Language.hpp		
    Language.cpp
    LexerConstants.hpp	
    LexerConstants.cpp
    Config.hpp			
    Config.cpp
    felide.cpp
)

set (felide_view_src
    view/Editor.hpp
    view/Editor.cpp
    view/View.hpp
    view/View.cpp
    view/Dialog.hpp
    view/Dialog.cpp
    view/DialogFactory.hpp
    view/DialogFactory.cpp
    view/MainFrame.hpp
    view/MainFrame.cpp
    view/MainFrameHandler.hpp
    view/MainFrameHandler.cpp
)

set (felide_view_gen_src
    view/gen/Menu.hpp               
    view/gen/Menu.cpp
    view/gen/Shortcut.hpp           
    view/gen/Shortcut.cpp
    view/gen/Generator.hpp          
    view/gen/Generator.cpp
    view/gen/DefaultGenerator.hpp  
    view/gen/DefaultGenerator.cpp
    view/gen/WindowsGenerator.hpp  
    view/gen/WindowsGenerator.cpp
)

add_executable(felide 
    ${felide_src} 
    ${felide_system_src} 
    ${felide_view_src} 
    ${felide_view_gen_src}
)

source_group(\\             FILES ${felide_src})
source_group(\\view         FILES ${felide_view_src})
source_group(\\view\\gen    FILES ${felide_view_gen_src})

target_link_libraries(felide ${Boost_LIBRARIES} ${FELIDE_QT5_LIBRARIES} ${FELIDE_WCL_LIBRARIES} felide.proj.cmake)

install (TARGETS felide DESTINATION ".")
install (FILES  )
