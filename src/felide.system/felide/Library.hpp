
#ifndef __felide_core_library_hpp__
#define __felide_core_library_hpp__

#include <string>

namespace felide {
    class Library {
    public:
        virtual ~Library();

        virtual void* getAddress(const std::string &procedureName) = 0;
    };
}

#endif
