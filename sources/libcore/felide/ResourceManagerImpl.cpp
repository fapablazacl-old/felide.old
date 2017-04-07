
#include "ResourceManagerImpl.hpp"
#include "Resource.hpp"

#include <map>
#include <cassert>

namespace felide {

    struct ResourceKey {
        explicit ResourceKey(Resource *resource) 
            : name(resource->getName()), typeIndex(typeid(*resource)) {}

        ResourceKey(const std::string &name_, const std::type_index &typeIndex_) 
            : name(name_), typeIndex(typeIndex_) {}

        std::string name;
        std::type_index typeIndex;

        bool operator<(const ResourceKey &other) const {
            if (name < other.name) {
                return false;
            }

            if (typeIndex < other.typeIndex) {
                return false;
            }

            return true;
        }
    };

    struct ResourceManagerImpl::Private {
        std::map<ResourceKey, std::unique_ptr<Resource>> m_resources;
    };

    ResourceManagerImpl::ResourceManagerImpl() 
        : m_impl(new ResourceManagerImpl::Private()) {}

    ResourceManagerImpl::~ResourceManagerImpl() {}

    const Resource* ResourceManagerImpl::getResource(const std::string &name, const std::type_index &index) const {
        assert(m_impl);

        const auto key = ResourceKey(name, index);
        const auto resourceIt = m_impl->m_resources.find(key);

        assert(resourceIt != m_impl->m_resources.end());
        assert(resourceIt->second);

        return resourceIt->second.get();
    }

    ResourceManager* ResourceManagerImpl::addResource(std::unique_ptr<Resource> resource) {
        assert(m_impl);
        assert(resource);

        const auto key = ResourceKey(resource.get());

        m_impl->m_resources[key] = std::move(resource);

        return this;
    }
}
