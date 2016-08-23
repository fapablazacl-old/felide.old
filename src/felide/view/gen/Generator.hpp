
#ifndef __felide_view_gen_generator_hpp__
#define __felide_view_gen_generator_hpp__

#include "Menu.hpp"

namespace felide { namespace view { namespace gen {
    class Generator {
    public:
        virtual ~Generator();

        virtual void generate(const Menu &menu) = 0;
    };
}}}

#endif
