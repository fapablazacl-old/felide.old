
# Force the C++ compiler to use UNICODE instead of ANSI
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

# disable those annoying Visual C++ warnings about deprecation..
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set (target felide.wcl)

set (sources 
	WAppImpl.hpp
	WAppImpl.cpp
	WMainFrame.cpp 
	WMainFrame.hpp 
	WMainFrame.ui.cpp 
	WDialogFactory.cpp 
	WDialogFactory.hpp 
	WEditor.cpp 
	WEditor.hpp 
)

add_library(${target} ${sources})
