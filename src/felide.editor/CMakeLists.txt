
IF (FELIDE_GUI_TOOLKIT_WIN32XX)
    SET(felide_editor_win32xx_src 
        win32xx/MainFrame.hpp 
        win32xx/MainFrame.cpp
        
        win32xx/Application.hpp 
        win32xx/Application.cpp
        
		win32xx/Editor.hpp 
        win32xx/Editor.cpp

		win32xx/EditorSci.hpp 
        win32xx/EditorSci.cpp

		win32xx/EditorText.hpp 
        win32xx/EditorText.cpp 
        
        win32xx/Module.hpp 
        win32xx/Module.cpp
    )
    
    SET(felide_editor_win32xx_res_src 
        win32xx/res/Resource.h
        win32xx/res/Resource.rc
        win32xx/res/bitmap1.bmp
    )
ENDIF ()

IF (FELIDE_GUI_TOOLKIT_QT5)
	SET (felide_editor_qt5_src 
		qt5/TabbedEditor.hpp
		qt5/TabbedEditor.cpp

		qt5/Editor.hpp
		qt5/Editor.cpp

		qt5/MainWindow.hpp
		qt5/MainWindow.cpp
		
		qt5/Application.hpp
		qt5/Application.cpp
	)

	QT5_WRAP_UI (felide_editor_qt5_ui
		qt5/MainWindow.ui
	)
ENDIF()

SET (felide_editor_gtk3mm_src )

SET (felide_editor_src 
    Main.cpp
	Application.hpp 
	Application.cpp
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

IF (FELIDE_GUI_TOOLKIT_WIN32XX)
    SOURCE_GROUP(win32xx FILES ${felide_editor_win32xx_src})
    SOURCE_GROUP(win32xx\\res FILES ${felide_editor_win32xx_res_src})
ENDIF ()

TARGET_LINK_LIBRARIES(felide.editor felide ${Boost_LIBRARIES} ${FELIDE_GUI_LIBRARIES})
