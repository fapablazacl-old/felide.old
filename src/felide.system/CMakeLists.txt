
set (target felide.system)

set (sources 
    "felide/Library.hpp"
    "felide/LibraryWin.cpp"
    "felide/Process.hpp"
    "felide/ProcessWin.cpp"
    "felide/ProcessWinRedirector.cpp"
    "felide/ProcessWinRedirector.hpp"
)

source_group (\\ FILES ${sources})

add_definitions (-DFELIDE_CORE_BUILD -DFELIDE_CORE_SHARED)
add_library (${target} SHARED ${sources})
