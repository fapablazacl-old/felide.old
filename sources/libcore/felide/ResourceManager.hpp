
/**
 * @brief Definition of the ResourceManager abstract class.
 */

#pragma once 

#ifndef __felide_resourcemanager_hpp__
#define __felide_resourcemanager_hpp__

#include <string>
#include <typeindex>
#include <memory>
#include <cassert>

namespace felide {
    class Resource;

    /**
     * @brief Interface for resource set and retrieval
     *
     * The Resource Manager is a specialiced interface for the various Resource classes used in the IDE.
     * Each resource's lifetime is tied to the resource manager. For more information about resources see the 
     * Resource class documentation.
     *
     * This class is intended to be populated with resources at the application initialization phase.
     */
    class ResourceManager {
    public:
        virtual ~ResourceManager();

        /**
         * @brief Get a Resource raw pointer.
         *
         * A resource 'key' is composed of both its name and index. This means that many resources can share the 
         * same name, but they all to be of different type. 
         */
        virtual const Resource* getResource(const std::string &name, const std::type_index &index) const = 0;

        /**
         * @brief Add a new Resource smart pointer
         *
         * The resource manager takes ownership of the supplied resource.
         */
        virtual ResourceManager* addResource(std::unique_ptr<Resource> resource) = 0;

        /**
         * @brief Utility, templated version of the abstract ResourceManager::getResource method.
         */
        template<typename T>
        const T* getResource(const std::string &name) const {
            auto resource = dynamic_cast<const T*>(this->getResource(name, std::type_index(typeid(T))));

            assert(resource);

            return resource;
        }
    };
}

#endif
