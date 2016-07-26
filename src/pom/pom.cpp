
#include "pom.hpp"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <iostream>

#include <cstdlib>

namespace felide { namespace pom {
    class BuilderImpl : public Builder {
    public:
        // build the supplied workspace
        virtual void build(Workspace *workspace) override {

            for (Project::Ptr &project : workspace->projects) {
                std::vector<std::string> objectFiles;

                // compile all the source files
                for (Item::Ptr &item : project->items) {
                    if (!project->language->isItemCompilable(item.get())) {
                        continue;
                    }

                    std::string compile = "cl /c " + item->path;

                    std::clog << compile << std::endl;

                    if (std::system(compile.c_str())) {
                        throw std::runtime_error("Compile error");
                    }

                    objectFiles.push_back(item->path + ".obj");
                }

                // once all of then are compiled, link together based on the project type
                std::string link;

                switch (project->type) {
                case ProjectType::ConsoleExecutable: 
                    link = "link ${files} /OUT:${target}.exe"; 
                    break;

                case ProjectType::StaticLibrary: 
                    link = "lib ${files} /OUT:${target}.lib"; 
                    break;

                default:
                    throw std::runtime_error("Unsupported target.");
                }

                boost::replace_all(link, "${files}", boost::join(objectFiles, " "));
                boost::replace_all(link, "${target}", project->name);

                std::clog << link << std::endl;

                if (std::system(link.c_str())) {
                    throw std::runtime_error("Link Error");
                }
            }
        }

    };
}}

int main() {
    using namespace felide::pom;

    Language lang;

    Workspace ws;
    ws.name = "test_workspace";
    ws.projects.emplace_back(new Project("mylib", "assets/simplews/mylib/mylib.project", ProjectType::StaticLibrary));
    ws.projects.emplace_back(new Project("mylib", "assets/simplews/myexe/myexe.project", ProjectType::ConsoleExecutable));

    Project *library = ws.projects[0].get();
    library->language = &lang;
    library->items.emplace_back(new Item("", "assets/simplews/mylib/mylib.hpp"));
    library->items.emplace_back(new Item("", "assets/simplews/mylib/mylib.cpp"));

    Project *executable = ws.projects[1].get();
    executable->language = &lang;
    executable->items.emplace_back(new Item("", "assets/simplews/myexe/myexe.hpp"));

    BuilderImpl builder;

    builder.build(&ws);

    return 0;
}
