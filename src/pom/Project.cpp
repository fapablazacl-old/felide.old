
#include "Project.hpp"
#include "Item.hpp"

namespace felide { namespace pom {
    Project::Project(std::string name_, std::string path_, ProjectType::Enum type_) 
            : name(name_), path(path_), type(type_) {}

    Project::~Project() {}
}}
