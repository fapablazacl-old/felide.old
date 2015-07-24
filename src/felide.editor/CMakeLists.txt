
SET(felide_editor_win32xx_src 
	win32xx/MainFrameWin32xx.hpp 
	win32xx/MainFrameWin32xx.cpp
	
	win32xx/ApplicationWin32xx.hpp 
	win32xx/ApplicationWin32xx.cpp
	
	win32xx/ScintillaWin32xx.hpp 
	win32xx/ScintillaWin32xx.cpp
	
	win32xx/ModuleWin32xx.hpp 
	win32xx/ModuleWin32xx.cpp
)

SET(felide_editor_win32xx_res_src 
	win32xx/res/Resource.h
	win32xx/res/Resource.rc
	win32xx/res/bitmap1.bmp
)

SET(felide_editor_qt5_src )
SET(felide_editor_gtk3mm_src )

SET(felide_editor_src 
	Application.hpp 
	Application.cpp 
	
	MainFrame.hpp 
	MainFrame.cpp 
)

ADD_EXECUTABLE(felide.editor WIN32 
	${felide_editor_src} 
	${felide_editor_win32xx_src}
	${felide_editor_win32xx_res_src}
)

SOURCE_GROUP(\\ FILES ${felide_editor_src})
SOURCE_GROUP(win32xx FILES ${felide_editor_win32xx_src})
SOURCE_GROUP(win32xx\\res FILES ${felide_editor_win32xx_res_src})

TARGET_LINK_LIBRARIES(felide.editor felide ${Boost_LIBRARIES} ${WIN32XX_LIBRARIES})
