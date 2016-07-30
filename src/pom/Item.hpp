
#ifndef __felide_pom_item__
#define __felide_pom_item__

#include <memory>
#include <string>

namespace felide { namespace pom {
    struct Item {
        typedef std::unique_ptr<Item> Ptr;

        std::string path;

        Item(std::string path_);
    };
}}

#endif
