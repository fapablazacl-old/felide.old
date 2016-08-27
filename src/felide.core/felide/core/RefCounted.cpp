
#include "RefCounted.hpp"

#include <cassert>

namespace felide { namespace core {
    RefCounted::RefCounted() {}

    RefCounted::~RefCounted() {
        assert(m_refCount);
    }

    void RefCounted::addRef() {
        m_refCount++;
    }


    void RefCounted::release() {
        if (--m_refCount == 0) {
            delete this;
        }
    }
}}
