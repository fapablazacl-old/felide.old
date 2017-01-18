
#ifndef __felide_pom_buildergcc__
#define __felide_pom_buildergcc__

#include "Builder.hpp"

namespace felide { namespace pom {
    class BuilderGCC : public Builder {
    public:
        virtual void build(Workspace *workspace) override;
    };
}}

#endif
