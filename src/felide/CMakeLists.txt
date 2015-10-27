
SET (felide_src Felide.cpp)

SOURCE_GROUP(\\ FILES ${felide_src})

ADD_EXECUTABLE(felide ${felide_src})

SET_PROPERTY (TARGET felide PROPERTY CXX_STANDARD 14)

TARGET_LINK_LIBRARIES(felide felide.core)
