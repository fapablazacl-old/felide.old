
SET (felide_view_qt5_src
	felide/view/qt5/QDialogFactory.hpp
	felide/view/qt5/QDialogFactory.cpp
	felide/view/qt5/QEditor.hpp
	felide/view/qt5/QEditor.cpp
)


ADD_LIBRARY(felide.core.qt5 SHARED ${felide_view_qt5_src})
TARGET_LINK_LIBRARIES(felide.core.qt5 -lstdc++)
