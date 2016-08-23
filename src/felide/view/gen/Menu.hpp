
#pragma once

#ifndef __felide_view_gen_menu_hpp__
#define __felide_view_gen_menu_hpp__

#include <string>
#include <vector>

#include "Shortcut.hpp"

namespace felide { namespace view { namespace gen {
    
    enum class MenuStatus {
        Unchecked,
        Checked,
        Grayed
    };
    
    struct Menu {        
        Menu();
        Menu(std::string key);
        Menu(std::string key, MenuStatus status);

        Menu(std::string key, Shortcut shortcut);

        Menu(std::string key, Shortcut shortcut, MenuStatus status);

        Menu(std::string key, std::vector<Menu> childs);

        Menu(std::vector<Menu> childs);

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
}}}

#endif
