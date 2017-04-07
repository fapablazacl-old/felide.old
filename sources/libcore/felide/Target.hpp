
#pragma once

#ifndef __felide_target_hpp__
#define __felide_target_hpp__

#include <vector>
#include <memory>

namespace felide {
    class item;
    class Target {
    public:
        virtual ~Target();

        virtual size_t getItemCount() const = 0;

        virtual item* getItem(const size_t index) = 0;

        virtual const item* getItem(const size_t index) const = 0;
    };
}

#endif
