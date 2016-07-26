
#ifndef __felide_pom__
#define __felide_pom__

/* Project Object Model */

#include <string>
#include <vector>
#include <memory>

#include <boost/filesystem.hpp>

namespace felide { namespace pom {

    struct BuildTool {
    
    };

    struct Item {
        typedef std::unique_ptr<Item> Ptr;

        std::string name;
        std::string path;

        Item(std::string name_, std::string path_) 
            : name(name_), path(path_) {}
    };

    class Language {
    public:
        bool isItemCompilable(const Item *item) const {
            const boost::filesystem::path fspath(item->path);
            const std::string ext = fspath.extension().string();

            return ext == ".cpp";
        }
    };

    struct ProjectType {
        enum Enum {
            WindowsExecutable,
            ConsoleExecutable,
            StaticLibrary,
            DynamicLibrary
        };
    };

    struct Project {
        typedef std::unique_ptr<Project> Ptr;

        std::string name;
        std::string path;
        ProjectType::Enum type;

        Project(std::string name_, std::string path_, ProjectType::Enum type_) 
            : name(name_), path(path_), type(type_) {
        }

        std::vector<Item::Ptr> items;

        Language *language = nullptr;
    };

    struct Workspace {
        typedef std::unique_ptr<Workspace> Ptr;

        std::string name;
        std::string path;

        std::vector<Project::Ptr> projects;
    };

    class Builder {
    public:
        typedef std::unique_ptr<Builder> Ptr;

        virtual ~Builder() {}

        virtual void build(Workspace *workspace) = 0;
    };
}}

#endif
