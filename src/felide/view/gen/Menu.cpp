
#include "Menu.hpp"

namespace felide { namespace view { namespace gen {
    Menu::Menu() {}

    Menu::Menu(std::string key_) 
        : key(key_) {}

    Menu::Menu(std::string key_, MenuStatus status_)  
        : key(key_), status(status_) {}
        
    Menu::Menu(std::string key_, std::vector<Menu> childs_) 
        : key(key_), childs(std::move(childs_)) {}

    Menu::Menu(std::string key_, Shortcut shortcut_) : key(key_), shortcut(shortcut_) {}

    Menu::Menu(std::string key_, Shortcut shortcut_, MenuStatus status_) : key(key_), shortcut(shortcut_), status(status_) {}

    //Menu::Menu(std::string key_, std::string shortcut_) 
    //    : key(key_), shortcut(shortcut_) {}

    Menu::Menu(std::vector<Menu> childs_) 
        : childs(std::move(childs_)) {}
}}}
