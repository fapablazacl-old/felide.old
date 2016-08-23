
#pragma once

#ifndef __felide_view_gen_defaultgenerator_hpp__
#define __felide_view_gen_defaultgenerator_hpp__

#include "Generator.hpp"
#include <map>

namespace felide { namespace view { namespace gen {

    class DefaultGenerator : public Generator {
    public:
        DefaultGenerator(const std::map<std::string, std::string> &labels);

        virtual ~DefaultGenerator();

        virtual void generate(const Menu &menu) override;

    private:
        void generateImpl(const Menu &menu, const int level);

    private:
        std::map<std::string, std::string> m_labels;
    };
}}}

#endif
