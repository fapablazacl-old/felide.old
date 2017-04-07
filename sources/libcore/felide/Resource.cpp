
#include "Resource.hpp"

#include <cassert>

namespace felide {
    Resource::Resource(const std::string &name) 
        : m_name(name) {}

    Resource::~Resource() {}

    std::string Resource::getName() const {
        return m_name;
    }
}

namespace felide {
    StringResource::StringResource(const std::string &name) 
        : Resource(name) {}

    StringResource::~StringResource() {}

    StringResource* StringResource::set(const std::string &key, const std::string &value) {
        m_values[key] = value;

        return this;
    }

    std::string StringResource::get(const std::string &key) const {
        auto valueIt = m_values.find(key);

        assert(valueIt != m_values.end());

        return valueIt->second;
    }
}
