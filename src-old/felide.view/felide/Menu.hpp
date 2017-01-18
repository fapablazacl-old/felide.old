
#pragma once

#ifndef __felide_view_gen_menu_hpp__
#define __felide_view_gen_menu_hpp__

#include <string>
#include <vector>

#include "Shortcut.hpp"

namespace felide {
    
    enum class MenuStatus {
        Unchecked,
        Checked,
        Grayed
    };
    
    struct Menu {        
        Menu() {}

        Menu(std::string key_) 
            : key(key_) {}

        Menu(std::string key_, MenuStatus status_)  
            : key(key_), status(status_) {}
        
        Menu(std::string key_, std::vector<Menu> childs_) 
            : key(key_), childs(std::move(childs_)) {}

        Menu(std::string key_, Shortcut shortcut_) : key(key_), shortcut(shortcut_) {}

        Menu(std::string key_, Shortcut shortcut_, MenuStatus status_) : key(key_), shortcut(shortcut_), status(status_) {}

        //Menu(std::string key_, std::string shortcut_) 
        //    : key(key_), shortcut(shortcut_) {}

        Menu(std::vector<Menu> childs_) 
            : childs(std::move(childs_)) {}

        bool isItem() const {
            return childs.size() == 0;
        }

        bool isSeparator() const {
            return key == "-";
        }

        std::string key;
        Shortcut shortcut;
        MenuStatus status = MenuStatus::Unchecked;
        std::vector<Menu> childs;
    };
}

#endif
