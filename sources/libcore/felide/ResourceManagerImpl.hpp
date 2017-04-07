
#pragma once

#ifndef __felide_resourcemanagerimpl_hpp__
#define __felide_resourcemanagerimpl_hpp__

#include "ResourceManager.hpp"

namespace felide {
    class ResourceManagerImpl : public ResourceManager {
    public:
        ResourceManagerImpl();

        virtual ~ResourceManagerImpl();

        virtual const Resource* getResource(const std::string &name, const std::type_index &index) const override;

        virtual ResourceManager* addResource(std::unique_ptr<Resource> resource) override;

    private:
        struct Private;
        std::unique_ptr<Private> m_impl;
    };
}

#endif
