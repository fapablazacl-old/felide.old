
SET(felide_editor_win32xx_src
    felide/view/win32xx/CMainFrame.hpp
    felide/view/win32xx/CMainFrame.cpp
    felide/view/win32xx/CApplication.hpp
    felide/view/win32xx/CApplication.cpp
    felide/view/win32xx/CEditor.hpp
    felide/view/win32xx/CEditor.cpp
    felide/view/win32xx/CEditorFactory.hpp
    felide/view/win32xx/CEditorFactory.cpp
    felide/view/win32xx/CEditorFactoryImpl.hpp
    felide/view/win32xx/CEditorFactoryImpl.cpp
    felide/view/win32xx/CEditorBase.hpp
    felide/view/win32xx/CEditorBase.cpp
    felide/view/win32xx/CEditorSci.hpp
    felide/view/win32xx/CEditorSci.cpp
    felide/view/win32xx/CEditorSciFactory.hpp
    felide/view/win32xx/CEditorSciFactory.cpp
    felide/view/win32xx/CEditorText.hpp
    felide/view/win32xx/CEditorText.cpp
    felide/view/win32xx/CModule.hpp
    felide/view/win32xx/CModule.cpp
    felide/view/win32xx/CTabbedEditorPanel.hpp
    felide/view/win32xx/CTabbedEditorPanel.cpp
    felide/view/win32xx/CDialogFactory.hpp
    felide/view/win32xx/CDialogFactory.cpp
)

SET(felide_editor_win32xx_res_src
    felide/view/win32xx/res/Resource.h
    felide/view/win32xx/res/Resource.rc
    felide/view/win32xx/res/bitmap1.bmp
)

ADD_LIBRARY (
    felide.editor.win32 SHARED 
    ${felide_editor_win32xx_src} 
    ${felide_editor_win32xx_res_src}
)

TARGET_LINK_LIBRARIES(felide.editor.win32 felide.core felide.core.win32 -lstdc++)
