
SET (felide_editor_src
    felidetor.cpp

)

ADD_DEFINITIONS(-DFELIDE_BUILD -DFELIDE_SHARED)

ADD_EXECUTABLE (felidetor
    ${felide_editor_src}
)

SET_PROPERTY (TARGET felidetor PROPERTY CXX_STANDARD 14)

SOURCE_GROUP(\\ FILES ${felide_editor_src})

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CLANG_LIBRARIES "stdc++")
ENDIF()

TARGET_LINK_LIBRARIES(felidetor felide.core ${Boost_LIBRARIES} ${FELIDE_GUI_LIBRARIES} ${CLANG_LIBRARIES})

# INSTALL(TARGETS felidetor RUNTIME DESTINATION "bin")
