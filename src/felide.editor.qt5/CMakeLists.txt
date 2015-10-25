
SET (felide_editor_qt5_src
    felide/view/qt5/QTabbedEditor.hpp
    felide/view/qt5/QTabbedEditor.cpp

    felide/view/qt5/QMainFrame.hpp
    felide/view/qt5/QMainFrame.cpp

    felide/view/qt5/QApplication.hpp
    felide/view/qt5/QApplication.cpp
)

QT5_WRAP_UI (felide_editor_qt5_ui
    felide/view/qt5/QMainFrame.ui
)

ADD_LIBRARY(felide.editor.qt5 SHARED ${felide_editor_qt5_src} ${felide_editor_qt5_ui})
TARGET_LINK_LIBRARIES(felide.editor.qt5 -lstdc++)
