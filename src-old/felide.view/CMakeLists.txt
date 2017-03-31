
set (target felide.view)

set (sources
    "felide/Editor.cpp"
    "felide/Editor.hpp"
    "felide/Frame.cpp"
    "felide/Frame.hpp"
    "felide/ViewFactory.cpp"
    "felide/ViewFactory.hpp"
    "felide/Widget.cpp"
    "felide/Widget.hpp"
    "felide/FrameHandler.cpp"
    "felide/FrameHandler.hpp"
    "felide/Menu.hpp"
    "felide/Menu.cpp"
    "felide/Shortcut.hpp"
    "felide/Shortcut.cpp"
)

source_group(\\ FILES ${sources})

add_definitions (-DFELIDE_BUILD -DFELIDE_SHARED)
add_library (${target} SHARED ${sources})
