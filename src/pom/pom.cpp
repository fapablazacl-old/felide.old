
#include "Language.hpp"
#include "Workspace.hpp"
#include "Project.hpp"
#include "Item.hpp"
#include "BuilderGCC.hpp"
#include "BuilderVC.hpp"

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

    BuilderGCC builder;

    builder.build(&ws);

    return 0;
}
