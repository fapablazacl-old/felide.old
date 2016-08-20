
#include "Menu.hpp"

namespace felide { namespace view { namespace gen {
    Menu::Menu() {}

    Menu::Menu(std::string key_) 
        : key(key_) {}

    Menu::Menu(std::string key_, std::vector<Menu> childs_) 
        : key(key_), childs(std::move(childs_)) {}

    Menu::Menu(std::vector<Menu> childs_) 
        : childs(std::move(childs_)) {}
}}}
