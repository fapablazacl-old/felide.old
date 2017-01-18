
#ifndef __felide_pom_item__
#define __felide_pom_item__

#include <memory>
#include <string>

namespace felide { namespace pom {
    struct Item {
        std::string file;

        Item(std::string path_);

        /**
         * @brief Compute the object file name
         */
        std::string getObject() const {
            return file + ".obj";
        }
    };

    typedef std::unique_ptr<Item> ItemPtr;
}}

#endif
