
#ifndef __felide_pom_project__
#define __felide_pom_project__

#include <memory>
#include <string>
#include <vector>
#include "ProjectType.hpp"

namespace felide { namespace pom {
    class Language;

    struct Arch {
        enum Enum {
            Bit32,
            Bit64
        };
    };

    struct RuntimeLibrary {
        enum Enum {
            StaticDebug,
            StaticRelease,
            DynamicDebug,
            DynamicRelease
        };
    };

    struct Item;
    struct Project {
        typedef std::unique_ptr<Project> Ptr;

        std::string name;
        std::string path;
        ProjectType::Enum type;

        Arch::Enum arch;
        RuntimeLibrary::Enum runtime;

        std::vector<Project*> dependencies;
        std::vector<std::unique_ptr<Item>> items;

        Language *language = nullptr;

        Project(std::string name, ProjectType::Enum type, Arch::Enum arch=Arch::Bit32, RuntimeLibrary::Enum runtime=RuntimeLibrary::StaticDebug);
        ~Project();
    };
}}

#endif
