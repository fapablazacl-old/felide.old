
SET (felide_src Felide.cpp)

SOURCE_GROUP(\\ FILES ${felide_src})

ADD_EXECUTABLE(felide ${felide_src})

TARGET_LINK_LIBRARIES(felide felide.core)
