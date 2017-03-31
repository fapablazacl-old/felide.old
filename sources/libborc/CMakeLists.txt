
set (target libborc)

set (sources 
    "felide/Version.hpp"
    "felide/Version.cpp"
    "felide/ToolChain.hpp"
    "felide/ToolChain.cpp"
    "felide/ToolChainCpp.hpp"
    "felide/ToolChainCpp.cpp"

    "felide/Task.hpp"
    "felide/Task.cpp"
    "felide/Project.hpp"
    "felide/Project.cpp"
    "felide/CommandTask.hpp"
    "felide/CommandTask.cpp"
    "felide/DirectoryTask.hpp"
    "felide/DirectoryTask.cpp"
)

add_library(${target} ${sources})

source_group(\\felide FILES ${sources})
