
#include "ResourceManagerImpl.hpp"
#include "Resource.hpp"

namespace felide {

    ResourceManagerImpl::ResourceManagerImpl() {}

    ResourceManagerImpl::~ResourceManagerImpl() {}

    const Resource* ResourceManagerImpl::getResource(const std::string &name, const std::type_index &index) const {
        /*
        std::clog << "felide::ResourceManagerImpl::getResource: Retrieving resource '" << name << "' of type '" << index.name() << "' ..." << std::endl;
        for (const auto &resourcePair : m_impl->m_resources) {
            const ResourceKey resourceKey = resourcePair.first;

            std::clog << "    Resource '" << resourceKey.name << "' of type '" << resourceKey.typeIndex.name() << "'. " << std::endl;
        }
        */

        const auto key = name;
        const auto resourceIt = m_resources.find(key);

        assert(resourceIt != m_resources.end());
        assert(resourceIt->second);

        return resourceIt->second.get();
    }

    ResourceManager* ResourceManagerImpl::addResource(std::unique_ptr<Resource> resource) {
        assert(resource);

        const auto key = resource->getName();

        /*
        std::clog << "felide::ResourceManagerImpl::addResource: Adding resource '" << resource->getName() << "' of type '" << key.typeIndex.name() << "' ..." << std::endl;
        */

        m_resources[key] = std::move(resource);
        //assert(m_resources[key]);

        return this;
    }
}
