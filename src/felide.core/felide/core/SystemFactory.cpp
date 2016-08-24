
#include "SystemFactory.hpp"
#include "SystemFactoryImpl.hpp"

#if defined(_WIN32)
#include "win32/ProcessWin32.hpp"
#include "win32/LibraryWin32.hpp"

namespace felide { namespace core {
    typedef felide::core::win32::ProcessWin32 ProcessImpl;
    typedef felide::core::win32::LibraryWin32 LibraryImpl;
}}
#endif

namespace felide { namespace core {
    SystemFactory::~SystemFactory() {}

    std::unique_ptr<SystemFactory> SystemFactory::newInstance() {
        return std::make_unique<SystemFactoryImpl<ProcessImpl, LibraryImpl>>();      
    }
}}
