
SET (felide_editor_src
	felide/EditorMain.cpp
)

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

SOURCE_GROUP(felide					FILES ${felide_editor_src})
SOURCE_GROUP(felide/view/win32		FILES ${felide_editor_win32xx_src})
SOURCE_GROUP(felide/view/win32/res	FILES ${felide_editor_win32xx_res_src})

INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/src/felide.core.win32)
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/src/felide.editor)

ADD_EXECUTABLE (
    felide.editor.win32 WIN32 
	${felide_editor_src}
    ${felide_editor_win32xx_src} 
    ${felide_editor_win32xx_res_src}
)

SET_PROPERTY (TARGET felide.editor.win32 PROPERTY CXX_STANDARD 14)

TARGET_LINK_LIBRARIES(felide.editor.win32 felide.core felide.editor felide.core.win32)

INSTALL(TARGETS felide.editor.win32 DESTINATION ".")
