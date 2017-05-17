
#pragma once

#ifndef __felide_resourcemanagerimpl_hpp__
#define __felide_resourcemanagerimpl_hpp__

#include "Resource.hpp"
#include "ResourceManager.hpp"

#include <map>
#include <vector>
#include <cassert>
#include <iostream>

namespace felide {
    class ResourceManagerImpl : public ResourceManager {
    public:
        ResourceManagerImpl();

        virtual ~ResourceManagerImpl();

        virtual const Resource* getResource(const std::string &name, const std::type_index &index) const override;

        virtual ResourceManager* addResource(std::unique_ptr<Resource> resource) override;

    private:
        std::map<std::string, std::unique_ptr<Resource>> m_resources;
    };
}

#endif
