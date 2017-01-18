
#ifndef __felide_pom_workspace__
#define __felide_pom_workspace__

#include <memory>
#include <string>
#include <vector>

namespace felide { namespace pom {
    struct Project;
    struct Workspace {
        Workspace();
        Workspace(const std::string &path, const std::string &name);
        ~Workspace();

        std::string path;
        std::string name;
        std::vector<std::unique_ptr<Project>> projects;
    };
}}

#endif
