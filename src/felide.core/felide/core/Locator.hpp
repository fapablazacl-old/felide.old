
#pragma once

#ifndef __felide_core_locator_hpp__
#define __felide_core_locator_hpp__

#include <string>
#include <list>

namespace felide {  namespace core {
    class Locator {
    public:
        void addPath(const std::string &path) {
            m_paths.push_back(path);
        }

        std::string locate(const std::string &name);

    private:
        std::list<std::string> m_paths;
    };
}}

#endif
