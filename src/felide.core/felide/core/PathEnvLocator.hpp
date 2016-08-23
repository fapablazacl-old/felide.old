
#pragma once

#ifndef __felide_core_pathenvlocator_hpp__
#define __felide_core_pathenvlocator_hpp__

#include "Locator.hpp"

#include <list>

namespace felide {  namespace core {
    class PathEnvLocator : public Locator {
    public:
        virtual std::string locate(const std::string &name) override;
    };
}}

#endif
