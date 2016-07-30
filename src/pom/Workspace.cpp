
#include "Workspace.hpp"
#include "Project.hpp"

namespace felide { namespace pom {
    Workspace::Workspace() {}

    Workspace::Workspace(const std::string &path_, const std::string &name_) 
        : path(path_), name(name_) {}

    Workspace::~Workspace() {}
}}
