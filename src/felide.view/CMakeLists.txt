
set (target felide.view)

set (sources
    "felide/view/Editor.cpp"
    "felide/view/Editor.hpp"
    "felide/view/Frame.cpp"
    "felide/view/Frame.hpp"
    "felide/view/ViewFactory.cpp"
    "felide/view/ViewFactory.hpp"
    "felide/view/ViewManager.cpp"
    "felide/view/ViewManager.hpp"
    "felide/view/Widget.cpp"
    "felide/view/Widget.hpp"
    "felide/view/FrameHandler.cpp"
    "felide/view/FrameHandler.hpp"
    "felide/view/Menu.hpp"
    "felide/view/Menu.cpp"
    "felide/view/Shortcut.hpp"
    "felide/view/Shortcut.cpp"
)

source_group(\\ FILES ${sources})

add_library (${target} SHARED ${sources})
