
#include "Language.hpp"
#include "BuilderVC.hpp"
#include "Workspace.hpp"
#include "Project.hpp"
#include "Item.hpp"

#include <iostream>

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/replace.hpp>

#include <boost/range/algorithm/copy.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/copied.hpp>

namespace fs = boost::filesystem;

namespace felide { namespace pom {

    using boost::adaptors::filtered;
    using boost::adaptors::transformed;
    using boost::adaptors::copied;

    static std::string getLinkCommand(const ProjectType::Enum type) {
        switch (type) {
        case ProjectType::ConsoleExecutable: 
            return "link ${files} /OUT:${target}.exe"; 
            
        case ProjectType::StaticLibrary: 
            return "lib ${files} /OUT:${target}.lib"; 

        default:
            throw std::runtime_error("Unsupported target.");
        }
    }

    BuilderVC::BuilderVC() {
        //! Compute Visual C++ install directory 
        const std::string vcinstalldir = "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC";

        const std::vector<std::string> includes = {
            "include",
            "atlmfc\\include"
        };

        for (const std::string &include : includes) {
            fs::path path = fs::path(vcinstalldir) / include;
            m_includes.push_back("\"" + path.string() + "\"");
        }
    }

    void BuilderVC::build(Workspace *workspace) {
        assert(workspace);

        const auto basePath = fs::path(workspace->path) / fs::path(workspace->name);
        const auto outputPath = basePath / "build";

        fs::create_directory(outputPath);

        std::vector<std::string> commands;

        for (auto &project : workspace->projects) {
            const auto projectPath = basePath / project->name;

            const Language *lang = project->language;

            // collect compilable items
            auto compilables = project->items | filtered([&](ItemPtr &item) {
                return lang->isCompilable(item.get()); 
            });
             
            // get dependency include paths
            auto dependencyIncludes = project->dependencies | transformed([&](Project *dependency) {
                const fs::path projectPath = basePath / dependency->name;
                return "/I " + projectPath.string(); 
            });

            // TODO: insert first the compiler default include paths
            std::vector<std::string> includes;

            boost::copy(m_includes, std::back_inserter(includes));
            boost::copy(dependencyIncludes, std::back_inserter(includes));

            std::string includeOption = boost::join(includes, " ");

            // build compile commands
            auto compileCommands = compilables | transformed([&](ItemPtr &item){ 
                const auto sourceFile = (projectPath / item->file).string();
                const auto objectFile = (outputPath / item->getObject()).string();

                return "cl /c " + sourceFile + " /Fo" + objectFile + " " + includeOption; 
            });

            // append the new compile commands
            boost::copy(compileCommands, std::back_inserter(commands));

            // build the link command
            auto objects = compilables | transformed([&](ItemPtr &item){ 
                return (outputPath / item->getObject()).string(); 
            });

            std::string link = getLinkCommand(project->type);

            boost::replace_all(link, "${files}", boost::join(objects, " "));
            boost::replace_all(link, "${target}", (outputPath / project->name).string());

            commands.push_back(link);
        }

        this->execute(commands);
    }
}}
