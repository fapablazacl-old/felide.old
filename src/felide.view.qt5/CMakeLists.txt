
SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Qt5Widgets
SET (CMAKE_INCLUDE_CURRENT_DIR ON)
SET (CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(QScintilla REQUIRED)

SET (FELIDE_GUI_LIBRARIES Qt5::Widgets ${QSCINTILLA_LIBRARY})

INCLUDE_DIRECTORIES(${QSCINTILLA_INCLUDE_DIR})

SET (felide_view_qt5_src
    felide/view/qt5/QDialogFactory.hpp
    felide/view/qt5/QDialogFactory.cpp
    felide/view/qt5/QEditor.hpp
    felide/view/qt5/QEditor.cpp
    felide/view/qt5/QTabbedEditor.hpp
    felide/view/qt5/QTabbedEditor.cpp
    felide/view/qt5/QMainFrame.hpp
    felide/view/qt5/QMainFrame.cpp
    felide/view/qt5/QApplication.hpp
    felide/view/qt5/QApplication.cpp
)

QT5_WRAP_UI (felide_view_qt5_ui
    felide/view/qt5/QMainFrame.ui
)

ADD_LIBRARY (
	felide.view.qt5
	${felide_view_qt5_src} 
	${felide_view_qt5_ui}
)

TARGET_LINK_LIBRARIES(felide.view.qt5 ${FELIDE_GUI_LIBRARIES})

