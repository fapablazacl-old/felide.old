
#include "Project.hpp"
#include "Item.hpp"

namespace felide { namespace pom {
    Project::Project(std::string name_, ProjectType::Enum type_,  Arch::Enum arch_, RuntimeLibrary::Enum runtime_) 
            : name(name_), type(type_), arch(arch_), runtime(runtime_) {}

    Project::~Project() {}
}}
