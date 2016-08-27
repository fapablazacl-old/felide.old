
#ifndef __felide_view_gen_generator_hpp__
#define __felide_view_gen_generator_hpp__

#include <felide/core/PreDef.hpp>
#include <felide/core/view/gen/Menu.hpp>

namespace felide { namespace view { namespace gen {
    class FELIDE_CORE_API Generator {
    public:
        virtual ~Generator() {}

        virtual void generate(const Menu &menu) = 0;
    };
}}}

#endif
