
IF (FELIDE_GEN_QT5)
	# Qt5Widgets
	
	FIND_PACKAGE(Qt5Widgets REQUIRED)
	FIND_PACKAGE(QScintilla REQUIRED)
	
	SET (CMAKE_AUTOUIC ON)
	SET (CMAKE_INCLUDE_CURRENT_DIR ON)
	SET (CMAKE_AUTOMOC ON)
    
	SET (FELIDE_VIEW_QT5_LIBRARIES Qt5::Widgets ${QSCINTILLA_LIBRARY})
	
	INCLUDE_DIRECTORIES(${QSCINTILLA_INCLUDE_DIR})
	
	SET (felide_view_qt5_src
        view/qt5/QApplication.hpp view/qt5/QApplication.cpp
	    view/qt5/QDialogFactory.hpp view/qt5/QDialogFactory.cpp
	    view/qt5/QEditor.hpp view/qt5/QEditor.cpp
	    view/qt5/QTabbedEditor.hpp view/qt5/QTabbedEditor.cpp
	    view/qt5/QMainFrame.hpp view/qt5/QMainFrame.cpp
        view/qt5/QMainPanel.hpp view/qt5/QMainPanel.cpp
        view/qt5/QWorkspaceView.hpp view/qt5/QWorkspaceView.cpp
        view/qt5/QWorkspaceModel.hpp view/qt5/QWorkspaceModel.cpp
	)

	QT5_WRAP_UI (felide_view_qt5_ui
	    view/qt5/QMainFrame.ui
	)

	ADD_DEFINITIONS(-DFELIDE_VIEW_QT5)
ENDIF()

IF (FELIDE_GEN_WIN32)
	# Win32xx
	IF (NOT WIN32XX_INCLUDE_DIRS)
	    MESSAGE (ERROR_MESSAGE "Win32++ include location isn't defined. Please define the WIN32XX_INCLUDE_DIRS variable.")
	    SET (WIN32XX_FOUND 0)
	    SET (WIN32XX_LIBRARIES )
	ELSE ()
	    SET (WIN32XX_FOUND 1)
	    SET (WIN32XX_LIBRARIES comctl32)
	ENDIF ()

	IF (NOT SCINTILLA_INCLUDE_DIRS)
	    MESSAGE (WARNING "Scintilla include location isn't defined (-DSCINTILLA_INCLUDE_DIRS). Using raw text editor widget.")
	    SET (SCINTILLA_FOUND 0)
	    SET (SCINTILLA_LIBRARIES)
	ELSE ()
	    SET (SCINTILLA_FOUND 1)
	    SET (SCINTILLA_LIBRARIES)
	ENDIF ()

	IF (SCINTILLA_FOUND)
	    ADD_DEFINITIONS(-DFELIDE_GUI_CODEEDIT_SCI)
	ELSE ()
	    ADD_DEFINITIONS(-DFELIDE_GUI_CODEEDIT_TEXT)
	ENDIF ()

	INCLUDE_DIRECTORIES (${WIN32XX_INCLUDE_DIRS})
	INCLUDE_DIRECTORIES (${SCINTILLA_INCLUDE_DIRS})

	SET (FELIDE_VIEW_WIN32_LIBRARIES )

	SET (felide_view_win32_src
	    view/win32/CDialogFactory.hpp
	    view/win32/CDialogFactory.cpp
	    view/win32/CEditor.hpp
	    view/win32/CEditor.cpp
	    view/win32/CEditorBase.hpp
	    view/win32/CEditorBase.cpp
	    view/win32/CEditorFactory.hpp
	    view/win32/CEditorFactory.cpp
	    view/win32/CEditorFactoryImpl.hpp
	    view/win32/CEditorFactoryImpl.cpp
	    view/win32/CEditorSci.hpp
	    view/win32/CEditorSci.cpp
	    view/win32/CEditorSciFactory.hpp
	    view/win32/CEditorSciFactory.cpp
	    view/win32/CEditorText.hpp
	    view/win32/CEditorText.cpp
	    view/win32/CModule.hpp
	    view/win32/CModule.cpp
	)
	
	ADD_DEFINITIONS(-DFELIDE_VIEW_WIN32)
ENDIF()


SET(felide_src
    Config.hpp
    Common.hpp
    ProjectItem.hpp 
    ProjectItem.cpp
    Project.hpp 
    Project.cpp
    Workspace.hpp 
    Workspace.cpp
    Toolchain.hpp 
    Toolchain.cpp
    Application.hpp 
    Application.cpp
    felide.cpp
)

SET(felide_system_src
    system/Environment.hpp 
    system/Environment.cpp
    system/Module.hpp 
    system/Module.cpp
    system/Process.hpp 
    system/ProcessWin32.cpp
    system/ProcessUnix.cpp
    system/Library.hpp 
    system/Library.cpp
)

SET (felide_view_src
    view/Editor.hpp
    view/Editor.cpp
    view/View.hpp
    view/View.cpp
    view/Handler.hpp
    view/Handler.cpp
    view/Dialog.hpp
    view/Dialog.cpp
    view/DialogFactory.hpp
    view/DialogFactory.cpp
    view/MainFrame.hpp
    view/MainFrame.cpp
    view/MainFrameHandler.hpp
    view/MainFrameHandler.cpp
)


ADD_EXECUTABLE(felide 
  ${felide_src} 
  ${felide_system_src} 
  ${felide_view_src} 
  ${felide_view_qt5_src} 
  ${felide_view_win32_src}
)

SET_PROPERTY(TARGET felide PROPERTY CXX_STANDARD 14)
SOURCE_GROUP(\\             FILES ${felide_src})
SOURCE_GROUP(\\system       FILES ${felide_system_src})
SOURCE_GROUP(\\view         FILES ${felide_view_src})
SOURCE_GROUP(\\view\\qt5    FILES ${felide_view_qt5_src})
SOURCE_GROUP(\\view\\win32  FILES ${felide_view_win32_src})

TARGET_LINK_LIBRARIES(felide ${Boost_LIBRARIES} ${FELIDE_VIEW_QT5_LIBRARIES} ${FELIDE_VIEW_WIN32_LIBRARIES})
# TARGET_LINK_LIBRARIES(felide ${Boost_LIBRARIES}  ${FELIDE_VIEW_QT5_LIBRARIES})

INSTALL(TARGETS felide DESTINATION "bin")
