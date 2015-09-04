/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __felide_common_hpp__
#define __felide_common_hpp__

#include <memory>

#if defined(__GNUG__)
#include <utility>

namespace std {
    template<typename Type, typename... Args>
    std::unique_ptr<Type> make_unique(Args&&... args) {
        return std::unique_ptr<Type>(new Type(std::forward<Args>(args)...));
    }
}
#endif

#endif // __felide_common_hpp__
