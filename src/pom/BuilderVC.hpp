
#ifndef __felide_pom_buildervc__
#define __felide_pom_buildervc__

#include <string>
#include <vector>

#include "Builder.hpp"

namespace felide { namespace pom {
    class BuilderVC : public Builder {
    public:
        BuilderVC();

        virtual void build(Workspace *workspace) override;

    private:
        //! Default Visual C++ include directories
        std::vector<std::string> m_includes;
    };
}}

#endif
