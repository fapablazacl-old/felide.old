
SET (felide_editor_src
	felide/view/MainFrame.hpp
	felide/view/MainFrame.cpp
	felide/view/MainFrameHandler.hpp
	felide/view/MainFrameHandler.cpp
)

ADD_LIBRARY (felide.editor SHARED
	${felide_editor_src}
)

SET_PROPERTY (TARGET felide.editor PROPERTY CXX_STANDARD 14)

SOURCE_GROUP(\\ FILES ${felide_editor_src})

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CLANG_LIBRARIES "stdc++")
ENDIF()

TARGET_LINK_LIBRARIES(felide.editor felide.core ${Boost_LIBRARIES} ${FELIDE_GUI_LIBRARIES} ${CLANG_LIBRARIES})
