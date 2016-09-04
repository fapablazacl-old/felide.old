
set (target felide.core)

set (sources 
    "felide/core/RefCounted.cpp" 
    "felide/core/RefCounted.hpp" 
    "felide/core/Plugin.cpp" 
    "felide/core/Plugin.hpp" 
    "felide/core/PluginLibrary.cpp" 
    "felide/core/PluginLibrary.hpp" 
    "felide/core/PluginManager.cpp" 
    "felide/core/PluginManager.hpp" 
    "felide/core/PluginManagerImpl.cpp" 
    "felide/core/PluginManagerImpl.hpp" 
    "felide/core/Locator.cpp" 
    "felide/core/Locator.hpp" 
    "felide/core/PathEnvLocator.cpp" 
    "felide/core/PathEnvLocator.hpp" 
    "felide/core/ArbitraryLocator.cpp" 
    "felide/core/ArbitraryLocator.hpp" 
    "felide/core/FileUtil.cpp" 
    "felide/core/FileUtil.hpp" 
    "felide/core/PreDef.cpp" 
    "felide/core/PreDef.hpp" 
    "felide/core/Environment.cpp"
    "felide/core/Environment.hpp"
    "felide/core/Library.cpp"
    "felide/core/Library.hpp"
    "felide/core/Module.cpp"
    "felide/core/Module.hpp"
    "felide/core/SystemFactory.cpp"
    "felide/core/SystemFactory.hpp"
    "felide/core/SystemFactoryImpl.cpp"
    "felide/core/SystemFactoryImpl.hpp"
    "felide/core/Process.cpp"
    "felide/core/Process.hpp"
)

set (sources_std
    "felide/core/std/EnvironmentStd.cpp"
    "felide/core/std/EnvironmentStd.hpp"
    "felide/core/std/LibraryStd.cpp"
    "felide/core/std/LibraryStd.hpp"
    "felide/core/std/ModuleFactoryStd.cpp"
    "felide/core/std/ModuleFactoryStd.hpp"
    "felide/core/std/ModuleStd.cpp"
    "felide/core/std/ModuleStd.hpp"
    "felide/core/std/ProcessStd.cpp"
    "felide/core/std/ProcessStd.hpp"
)

set (sources_win32
    "felide/core/win32/EnvironmentWin32.cpp"
    "felide/core/win32/EnvironmentWin32.hpp"
    "felide/core/win32/LibraryWin32.cpp"
    "felide/core/win32/LibraryWin32.hpp"
    "felide/core/win32/SystemFactoryWin32.cpp"
    "felide/core/win32/SystemFactoryWin32.hpp"
    "felide/core/win32/ModuleWin32.cpp"
    "felide/core/win32/ModuleWin32.hpp"
    "felide/core/win32/ProcessWin32.cpp"
    "felide/core/win32/ProcessWin32.hpp"
    "felide/core/win32/ProcessRedirector.cpp"
    "felide/core/win32/ProcessRedirector.hpp"
)

source_group(\\             FILES ${sources})
source_group(\\std          FILES ${sources_std})
source_group(\\win32        FILES ${sources_win32})

add_definitions(-DFELIDE_CORE_BUILD -DFELIDE_CORE_SHARED)
add_library (${target} SHARED ${sources} ${sources_std} ${sources_win32})
target_link_libraries (${target} ${Boost_LIBRARIES})
