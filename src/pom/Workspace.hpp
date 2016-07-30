
#ifndef __felide_pom_workspace__
#define __felide_pom_workspace__

#include <memory>
#include <string>
#include <vector>

namespace felide { namespace pom {
    struct Project;
    struct Workspace {
        std::string name;
        std::string path;

        std::vector<std::unique_ptr<Project>> projects;
    };
}}

#endif
