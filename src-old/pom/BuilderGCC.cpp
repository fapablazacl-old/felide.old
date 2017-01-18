
#include "BuilderGCC.hpp"
#include "Workspace.hpp"
#include "Project.hpp"
#include "Item.hpp"

#include <vector>
#include <string>
#include <cassert>
#include <boost/filesystem/path.hpp>

namespace fs = boost::filesystem;

namespace felide { namespace pom {
    static std::string getBuildCommand(const ProjectType::Enum type) {
        switch (type) {
        case ProjectType::ConsoleExecutable: 
            return "gcc %s -o %s -lm -lstdc++";;

        case ProjectType::StaticLibrary:
            return "gcc %s -o %s -lm -lstdc++";;
        }
    }

    void BuilderGCC::build(Workspace *workspace) {
        assert(workspace);

        std::vector<std::string> commands;

        // generate command list
        for (auto &project : workspace->projects) {
            std::vector<std::string> objectFiles;

            for (auto &item : project->items) {
                std::string compileCmd = "gcc %s -c -o %s";

                commands.push_back(compileCmd);
            }

            std::string linkCmd = getBuildCommand(project->type);

            commands.push_back(linkCmd);
        }

        // build the command
        this->execute(commands);
    }
}}
