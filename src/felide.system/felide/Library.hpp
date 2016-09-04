
#pragma once

#ifndef __felide_library_hpp__
#define __felide_library_hpp__

#include <string>
#include <felide/PreDef.hpp>

namespace felide {
    class FELIDE_CORE_API Library {
    public:
        Library(const std::string &name);

        ~Library();

        void* getAddress(const std::string &procedureName);

    private:
        Library(const Library&) = delete;
        void operator=(const Library&) = delete;

    private:
        struct Private;
        Private* m_impl;
    };
}

#endif
