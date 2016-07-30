
#ifndef __felide_pom_project__
#define __felide_pom_project__

#include <memory>
#include <string>
#include <vector>
#include "ProjectType.hpp"

namespace felide { namespace pom {
    class Language;

    struct Item;
    struct Project {
        typedef std::unique_ptr<Project> Ptr;

        std::string name;
        std::string path;
        ProjectType::Enum type;

        std::vector<Project*> dependencies;
        std::vector<std::unique_ptr<Item>> items;

        Language *language = nullptr;

        Project(std::string name_, std::string path, ProjectType::Enum type);
        ~Project();
    };
}}

#endif
