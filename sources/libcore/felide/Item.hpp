
#pragma once

#ifndef __felide_item_hpp__
#define __felide_item_hpp__

#include <string>

namespace felide {
    /**
     * @brief Item of a Target.
     */
    class Item {
    public:
        virtual ~Item();

        /**
         * @brief Returns 'true' if the item has a physical path.
         */
        virtual bool hasPath() const = 0;

        /**
         * @brief Get the physical relative location of the item.
         */
        virtual std::string getPath() const = 0;
    };
}

#endif
