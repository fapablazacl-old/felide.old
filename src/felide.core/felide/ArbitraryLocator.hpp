
#pragma once

#ifndef __felide_core_arbitrarylocator_hpp__
#define __felide_core_arbitrarylocator_hpp__

#include "Locator.hpp"

#include <list>

namespace felide {
    class ArbitraryLocator : public Locator {
    public:
        void addPath(const std::string &path) {
            m_paths.push_back(path);
        }

        virtual std::string locate(const std::string &name) override;

    private:
        std::list<std::string> m_paths;
    };
}

#endif
