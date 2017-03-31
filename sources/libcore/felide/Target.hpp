
#pragma once

#ifndef __felide_target_hpp__
#define __felide_target_hpp__

#include <vector>
#include <memory>

namespace felide {
    class Item;
    class Target {
    public:
        virtual ~Target();

        virtual size_t getItemCount() const = 0;

        virtual Item* getItem(const size_t index) = 0;

        virtual const Item* getItem(const size_t index) const = 0;
    };
}

#endif
