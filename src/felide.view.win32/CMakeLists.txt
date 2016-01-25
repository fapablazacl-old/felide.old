
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

SET (FELIDE_GUI_LIBRARIES )

SET (felide_view_win32_src
    felide/view/win32/CDialogFactory.hpp
    felide/view/win32/CDialogFactory.cpp
    felide/view/win32/CEditor.hpp
    felide/view/win32/CEditor.cpp
    felide/view/win32/CEditorBase.hpp
    felide/view/win32/CEditorBase.cpp
    felide/view/win32/CEditorFactory.hpp
    felide/view/win32/CEditorFactory.cpp
    felide/view/win32/CEditorFactoryImpl.hpp
    felide/view/win32/CEditorFactoryImpl.cpp
    felide/view/win32/CEditorSci.hpp
    felide/view/win32/CEditorSci.cpp
    felide/view/win32/CEditorSciFactory.hpp
    felide/view/win32/CEditorSciFactory.cpp
    felide/view/win32/CEditorText.hpp
    felide/view/win32/CEditorText.cpp
    felide/view/win32/CModule.hpp
    felide/view/win32/CModule.cpp
)

ADD_LIBRARY(felide.view.win32 ${felide_view_win32_src})

SET_PROPERTY (TARGET felide.view.win32 PROPERTY CXX_STANDARD 14)

SOURCE_GROUP(\\ FILES ${felide_view_win32_src})

TARGET_LINK_LIBRARIES(felide.view.win32 felide.core ${WIN32XX_LIBRARIES})

