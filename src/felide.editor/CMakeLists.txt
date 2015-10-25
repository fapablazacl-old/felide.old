
IF (FELIDE_GUI_TOOLKIT_WIN32XX)
    SET(felide_editor_win32xx_src
        felide/win32xx/CMainFrame.hpp
        felide/win32xx/CMainFrame.cpp

        felide/win32xx/CApplication.hpp
        felide/win32xx/CApplication.cpp

		felide/win32xx/CEditor.hpp
        felide/win32xx/CEditor.cpp

		felide/win32xx/CEditorFactory.hpp
        felide/win32xx/CEditorFactory.cpp

		felide/win32xx/CEditorFactoryImpl.hpp
        felide/win32xx/CEditorFactoryImpl.cpp

		felide/win32xx/CEditorBase.hpp
        felide/win32xx/CEditorBase.cpp

		felide/win32xx/CEditorSci.hpp
        felide/win32xx/CEditorSci.cpp

		felide/win32xx/CEditorSciFactory.hpp
        felide/win32xx/CEditorSciFactory.cpp

		felide/win32xx/CEditorText.hpp
        felide/win32xx/CEditorText.cpp

        felide/win32xx/CModule.hpp
        felide/win32xx/CModule.cpp

		felide/win32xx/CTabbedEditorPanel.hpp
		felide/win32xx/CTabbedEditorPanel.cpp
		
		felide/win32xx/CDialogFactory.hpp
		felide/win32xx/CDialogFactory.cpp
    )

    SET(felide_editor_win32xx_res_src
        felide/win32xx/res/Resource.h
        felide/win32xx/res/Resource.rc
        felide/win32xx/res/bitmap1.bmp
    )
ENDIF ()

IF (FELIDE_GUI_TOOLKIT_QT5)
	SET (felide_editor_qt5_src
		felide/qt5/QTabbedEditor.hpp
		felide/qt5/QTabbedEditor.cpp

		felide/qt5/QEditor.hpp
		felide/qt5/QEditor.cpp

		felide/qt5/QMainFrame.hpp
		felide/qt5/QMainFrame.cpp

		felide/qt5/QApplication.hpp
		felide/qt5/QApplication.cpp

		felide/qt5/QDialogFactory.hpp
		felide/qt5/QDialogFactory.cpp
	)

	QT5_WRAP_UI (felide_editor_qt5_ui
		felide/qt5/QMainFrame.ui
	)
ENDIF()

SET (felide_editor_gtk3mm_src )

SET (felide_editor_src
    felide/Main.cpp

	felide/Application.hpp
	felide/Application.cpp

	felide/Editor.hpp
	felide/Editor.cpp

	felide/View.hpp
	felide/View.cpp

	felide/Handler.hpp
	felide/Handler.cpp

	felide/MainFrame.hpp
	felide/MainFrame.cpp

	felide/MainFrameHandler.hpp
	felide/MainFrameHandler.cpp

	felide/DialogFactory.hpp
	felide/DialogFactory.cpp
)

ADD_LIBRARY (felide.editor SHARED
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

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CLANG_LIBRARIES "stdc++")
ENDIF()

TARGET_LINK_LIBRARIES(felide.editor felide.core ${Boost_LIBRARIES} ${FELIDE_GUI_LIBRARIES} ${CLANG_LIBRARIES})
