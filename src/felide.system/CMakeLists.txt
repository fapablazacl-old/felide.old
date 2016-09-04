
set (target felide.system)

set (sources 
    "felide/Library.hpp"
    "felide/LibraryWin.cpp"
    "felide/Process.hpp"
    "felide/ProcessWin.cpp"
    "felide/ProcessWinRedirector.cpp"
    "felide/ProcessWinRedirector.hpp"
)

source_group(\\ FILES ${sources})

add_library(${target} ${sources})
