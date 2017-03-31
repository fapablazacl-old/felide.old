
#ifndef __felide_pom_builder__
#define __felide_pom_builder__

#include <string>
#include <vector>

namespace felide { namespace pom {
    struct Workspace;

    class Builder {
    public:
        virtual ~Builder() {}

        // Build the supplied workspace
        virtual void build(Workspace *workspace) = 0;

    protected:
        // Execute the supplied command array. Throws exception when a command fails
        void execute(const std::vector<std::string> &commands);
    };
}}

#endif
