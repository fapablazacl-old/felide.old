
#include "Language.hpp"
#include "Workspace.hpp"
#include "Project.hpp"
#include "Item.hpp"
#include "BuilderGCC.hpp"
#include "BuilderVC.hpp"

#include <iostream>

int main(int argc, char **argv) {
    try {
        using namespace felide::pom;

        Language lang;

        Workspace ws("assets", "simplews");
        ws.projects.emplace_back(new Project("mylib", ProjectType::StaticLibrary));
        ws.projects.emplace_back(new Project("myexe", ProjectType::ConsoleExecutable));
        ws.projects[1]->dependencies.push_back(ws.projects[0].get());
        
        Project *library = ws.projects[0].get();
        library->language = &lang;
        library->items.emplace_back(new Item("mylib.hpp"));
        library->items.emplace_back(new Item("mylib.cpp"));

        Project *executable = ws.projects[1].get();
        executable->language = &lang;
        executable->items.emplace_back(new Item("myexe.cpp"));

        BuilderVC builder;
        builder.build(&ws);

        return EXIT_SUCCESS;
    } catch (const std::exception &exp) {
        std::cout << exp.what() << std::endl;

        return EXIT_FAILURE;
    }
}
