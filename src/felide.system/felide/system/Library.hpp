
#ifndef __felide_system_library_hpp__
#define __felide_system_library_hpp__

#include <string>

namespace felide { namespace system {
    class Library {
    public:
        virtual ~Library();

        virtual void* getAddress(const std::string &procedureName) = 0;
    };
}}

#endif
