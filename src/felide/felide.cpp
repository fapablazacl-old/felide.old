
#include <map>
#include "felide/App.hpp"
#include "felide/view/gen/Menu.hpp"

#include <iostream>

int main(int argc, char **argv) {

    using felide::view::gen::Menu;

    std::map<std::string, std::string> labels_EN {
        {"file", "&File"}, 
        {"file.new", "&New"}, 
        {"file.open", "&Open ..."}, 
        {"file.save", "&Save"}, 
        {"file.saveall", "Save &All"}, 
        {"file.saveas", "Sa&ve As ..."}, 
        {"file.close", "&Close"}, 
        {"file.exit", "&Exit"}, 
        {"edit", "&Edit"}, 
        {"edit.undo", "&Undo"}, 
        {"edit.redo", "&Redo"}, 
        {"edit.copy", "C&opy"}, 
        {"edit.paste", "&Paste"}, 
        {"view", "&View"},
        {"view.output", "Output Window"},
        {"view.folder", "Folder View"},
        {"help", "&Help"},
        {"help.about", "About"}
    };

    Menu mainMenu = {{
        {"file", {
            {"file.new"}, 
            {"-"}, 
            {"file.open"}, 
            {"-"}, 
            {"file.save"}, 
            {"file.saveall"}, 
            {"file.saveas"}, 
            {"-"}, 
            {"file.close"}, 
            {"-"}, 
            {"file.exit"}, 
        }}, 
        
        {"edit", {
            {"edit.undo"}, 
            {"edit.redo"}, 

            {"edit.cut"}, 
            {"edit.copy"},
            {"edit.paste"}
        }}, 
        
        {"view", {
            {"view.output"},
            {"view.folder"}
        }}, 

        {"help", {
            {"help.about"}
        }}, 
    }};

    class Generator {
    public:
        Generator(const std::map<std::string, std::string> &labels) 
            : m_labels(labels) {}

        void generate(const Menu &menu, const int level=0) {
            std::cout << std::string(level, '-') << m_labels[menu.key] << std::endl;

            for (const Menu &child : menu.childs) {
                this->generate(child, level + 2);
            }
        }

    private:
        std::map<std::string, std::string> m_labels;
    };

    Generator generator(labels_EN);

    generator.generate(mainMenu);

    //try {
    //    return felide::App::getInstance()->run(argc, argv);

    //} catch (const std::exception &exp) {
    //    std::cout << exp.what() << std::endl;
    //}

    return EXIT_SUCCESS;
}
