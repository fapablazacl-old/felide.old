
SET(felide_editor_win32xx_src
	felide/view/win32/CApplication.hpp
    felide/view/win32/CApplication.cpp
    felide/view/win32/CMainFrame.hpp
    felide/view/win32/CMainFrame.cpp
    felide/view/win32/CTabbedEditorPanel.hpp
    felide/view/win32/CTabbedEditorPanel.cpp
)

SET(felide_editor_win32xx_res_src
    felide/view/win32/res/Resource.h
    felide/view/win32/res/Resource.rc
    felide/view/win32/res/bitmap1.bmp
)

SOURCE_GROUP(\\		FILES ${felide_editor_win32xx_src})
SOURCE_GROUP(\\res	FILES ${felide_editor_win32xx_res_src})

INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/src/felide.core.win32)
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/src/felide.editor)

ADD_LIBRARY (
    felide.editor.win32 SHARED 
    ${felide_editor_win32xx_src} 
    ${felide_editor_win32xx_res_src}
)

TARGET_LINK_LIBRARIES(felide.editor.win32 felide.core felide.core.win32)
