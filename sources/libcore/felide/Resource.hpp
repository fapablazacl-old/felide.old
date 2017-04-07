
/**
 * @brief Definition of various Resource classes
 */

#pragma once

#ifndef __felide_resource_hpp__
#define __felide_resource_hpp__

#include <string>

namespace felide {
    class Resource {
    public:
        explicit Resource(const std::string &name);

        virtual ~Resource() = 0;

        virtual std::string getName() const;

    private:
        std::string m_name;
    };
}

namespace felide {
    template<typename T>
    class ResourceWrapper : public Resource {
    public:
        explicit ResourceWrapper(const std::string &name, const T &value) 
            : Resource(name), m_value(value) {}

        void set(const T& value) {
            m_value = value;
        }

        T get() const {
            return m_value;
        }

        virtual ~ResourceWrapper() {}

    private:
        T m_value;
    };
}

#include <map>

namespace felide {
    class StringResource : public Resource {
    public:
        explicit StringResource(const std::string &name);

        virtual ~StringResource();

        StringResource* set(const std::string &key, const std::string &value);

        std::string get(const std::string &key) const;

    private:
        std::map<std::string, std::string> m_values;
    };
}

#endif 
