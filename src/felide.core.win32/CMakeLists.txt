
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

ADD_LIBRARY(felide.core.win32 STATIC ${felide_view_win32_src})

SET_PROPERTY (TARGET felide.core.win32 PROPERTY CXX_STANDARD 14)

SOURCE_GROUP(\\ FILES ${felide_view_win32_src})

TARGET_LINK_LIBRARIES(felide.core.win32 felide.core comctl32)
