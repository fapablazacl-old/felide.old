
IF (WIN32XX_FOUND)
    SET(felide_editor_win32xx_src 
        win32xx/MainFrameWin32xx.hpp 
        win32xx/MainFrameWin32xx.cpp
        
        win32xx/ApplicationWin32xx.hpp 
        win32xx/ApplicationWin32xx.cpp
        
        win32xx/ScintillaWin32xx.hpp 
        win32xx/ScintillaWin32xx.cpp
        
        win32xx/ModuleWin32xx.hpp 
        win32xx/ModuleWin32xx.cpp
    )
    
    SET(felide_editor_win32xx_res_src 
        win32xx/res/Resource.h
        win32xx/res/Resource.rc
        win32xx/res/bitmap1.bmp
    )
ELSE ()
    SET(felide_editor_win32xx_src )
    SET(felide_editor_win32xx_res_src )
ENDIF ()

SET (felide_editor_qt5_src 
    qt5/TabbedEditor.hpp
    qt5/TabbedEditor.cpp

    qt5/MainWindow.hpp
    qt5/MainWindow.cpp
    
    qt5/Application.hpp
    qt5/Application.cpp
)

QT5_WRAP_UI (felide_editor_qt5_ui
    qt5/MainWindow.ui
)

SET (felide_editor_gtk3mm_src )

SET (felide_editor_src 
    Main.cpp
)

ADD_EXECUTABLE (felide.editor WIN32 
	${felide_editor_src} 
	${felide_editor_win32xx_src}
	${felide_editor_win32xx_res_src}
    ${felide_editor_qt5_src} 
    ${felide_editor_qt5_ui}
)

SET_PROPERTY (TARGET felide.editor PROPERTY CXX_STANDARD 14)

SOURCE_GROUP(\\ FILES ${felide_editor_src})

IF (WIN32XX_FOUND)
    SOURCE_GROUP(win32xx FILES ${felide_editor_win32xx_src})
    SOURCE_GROUP(win32xx\\res FILES ${felide_editor_win32xx_res_src})
ENDIF ()

TARGET_LINK_LIBRARIES(felide.editor felide ${Boost_LIBRARIES} ${FELIDE_GUI_LIBRARIES})
