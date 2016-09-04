
set (target felide.system)

set (sources 
    "felide/Environment.cpp" 
    "felide/Environment.hpp"
    "felide/Library.cpp"
    "felide/Library.hpp"
    "felide/Module.cpp"
    "felide/Module.hpp"
    "felide/Process.cpp"
    "felide/Process.hpp"
    "felide/SystemFactory.cpp"
    "felide/SystemFactory.hpp"
    "felide/SystemFactoryImpl.cpp"
    "felide/SystemFactoryImpl.hpp" 
)

set (sources_std
    "felide/std/EnvironmentStd.cpp"
    "felide/std/EnvironmentStd.hpp"
    "felide/std/LibraryStd.cpp"
    "felide/std/LibraryStd.hpp"
    "felide/std/ModuleFactoryStd.cpp"
    "felide/std/ModuleFactoryStd.hpp"
    "felide/std/ModuleStd.cpp"
    "felide/std/ModuleStd.hpp"
    "felide/std/ProcessStd.cpp"
    "felide/std/ProcessStd.hpp"
)

set (sources_win32
    "felide/win32/EnvironmentWin32.cpp"
    "felide/win32/EnvironmentWin32.hpp"
    "felide/win32/LibraryWin32.cpp"
    "felide/win32/LibraryWin32.hpp"
    "felide/win32/SystemFactoryWin32.cpp"
    "felide/win32/SystemFactoryWin32.hpp"
    "felide/win32/ModuleWin32.cpp"
    "felide/win32/ModuleWin32.hpp"
    "felide/win32/ProcessWin32.cpp"
    "felide/win32/ProcessWin32.hpp"
    "felide/win32/ProcessRedirector.cpp"
    "felide/win32/ProcessRedirector.hpp"
)

source_group(\\         FILES ${sources})
source_group(\\std      FILES ${sources_std})
source_group(\\win32    FILES ${sources_win32})

add_library(${target} ${sources} ${sources_std} ${sources_win32})
