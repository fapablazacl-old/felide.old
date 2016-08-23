
set (target felide.system)

set (sources 
    "felide/system/Environment.cpp"
    "felide/system/Environment.hpp"
    "felide/system/Library.cpp"
    "felide/system/Library.hpp"
    "felide/system/Module.cpp"
    "felide/system/Module.hpp"
    "felide/system/ModuleFactory.cpp"
    "felide/system/ModuleFactory.hpp"
    "felide/system/Process.cpp"
    "felide/system/Process.hpp"
)

set (sources_std
    "felide/system/std/EnvironmentStd.cpp"
    "felide/system/std/EnvironmentStd.hpp"
    "felide/system/std/LibraryStd.cpp"
    "felide/system/std/LibraryStd.hpp"
    "felide/system/std/ModuleFactoryStd.cpp"
    "felide/system/std/ModuleFactoryStd.hpp"
    "felide/system/std/ModuleStd.cpp"
    "felide/system/std/ModuleStd.hpp"
    "felide/system/std/ProcessStd.cpp"
    "felide/system/std/ProcessStd.hpp"
)

set (sources_win32
    "felide/system/win32/EnvironmentWin32.cpp"
    "felide/system/win32/EnvironmentWin32.hpp"
    "felide/system/win32/LibraryWin32.cpp"
    "felide/system/win32/LibraryWin32.hpp"
    "felide/system/win32/ModuleFactoryWin32.cpp"
    "felide/system/win32/ModuleFactoryWin32.hpp"
    "felide/system/win32/ModuleWin32.cpp"
    "felide/system/win32/ModuleWin32.hpp"
    "felide/system/win32/ProcessWin32.cpp"
    "felide/system/win32/ProcessWin32.hpp"
    "felide/system/win32/ProcessRedirector.cpp"
    "felide/system/win32/ProcessRedirector.hpp"
)

source_group(\\ FILES ${sources})
source_group(\\std FILES ${sources_std})
source_group(\\win32 FILES ${sources_win32})

add_library (${target} ${sources} ${sources_std} ${sources_win32})
