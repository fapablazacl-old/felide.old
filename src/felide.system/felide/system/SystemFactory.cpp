
#include "SystemFactory.hpp"
#include "SystemFactoryImpl.hpp"

#if defined(_WIN32)
#include "win32/ProcessWin32.hpp"
#include "win32/LibraryWin32.hpp"

namespace felide { namespace system {
    typedef felide::system::win32::ProcessWin32 ProcessImpl;
    typedef felide::system::win32::LibraryWin32 LibraryImpl;
}}
#endif

namespace felide { namespace system {
    SystemFactory::~SystemFactory() {}

    std::unique_ptr<SystemFactory> SystemFactory::newInstance() {
#if defined(_WIN32)
        return std::make_unique<SystemFactoryImpl<ProcessImpl, LibraryImpl>>();
#endif        
    }
}}
