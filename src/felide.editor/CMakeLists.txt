
IF (FELIDE_GUI_TOOLKIT_WIN32XX)
    SET(felide_editor_win32xx_src
        win32xx/CMainFrame.hpp
        win32xx/CMainFrame.cpp

        win32xx/CApplication.hpp
        win32xx/CApplication.cpp

		win32xx/CEditor.hpp
        win32xx/CEditor.cpp

		win32xx/CEditorSci.hpp
        win32xx/CEditorSci.cpp

		win32xx/CEditorText.hpp
        win32xx/CEditorText.cpp

        win32xx/CModule.hpp
        win32xx/CModule.cpp

		win32xx/CTabbedEditorPanel.hpp
		win32xx/CTabbedEditorPanel.cpp

		win32xx/CDialogFactory.hpp
		win32xx/CDialogFactory.cpp
    )

    SET(felide_editor_win32xx_res_src
        win32xx/res/Resource.h
        win32xx/res/Resource.rc
        win32xx/res/bitmap1.bmp
    )
ENDIF ()

IF (FELIDE_GUI_TOOLKIT_QT5)
	SET (felide_editor_qt5_src
		qt5/QTabbedEditor.hpp
		qt5/QTabbedEditor.cpp

		qt5/QEditor.hpp
		qt5/QEditor.cpp

		qt5/QMainFrame.hpp
		qt5/QMainFrame.cpp

		qt5/QApplication.hpp
		qt5/QApplication.cpp

		qt5/QDialogFactory.hpp
		qt5/QDialogFactory.cpp
	)

	QT5_WRAP_UI (felide_editor_qt5_ui
		qt5/QMainFrame.ui
	)
ENDIF()

SET (felide_editor_gtk3mm_src )

SET (felide_editor_src
    Main.cpp

	Application.hpp
	Application.cpp

	Editor.hpp
	Editor.cpp

	View.hpp
	View.cpp

	Handler.hpp
	Handler.cpp

	MainFrame.hpp
	MainFrame.cpp

	MainFrameHandler.hpp
	MainFrameHandler.cpp

	DialogFactory.hpp
	DialogFactory.cpp
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
