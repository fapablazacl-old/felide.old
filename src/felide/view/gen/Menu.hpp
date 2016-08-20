
#pragma once

#ifndef __felide_view_gen_menu_hpp__
#define __felide_view_gen_menu_hpp__

#include <string>
#include <vector>

namespace felide { namespace view { namespace gen {
    
    enum class MenuStatus {
        Unchecked,
        Checked,
        Grayed
    };
    
    struct Menu {
        std::string key;
        MenuStatus status = MenuStatus::Unchecked;
        std::vector<Menu> childs;

        Menu();
        Menu(std::string key);
        Menu(std::string key, MenuStatus status);
        //Menu(std::string key, std::string shortcut);
        Menu(std::string key, std::vector<Menu> childs);
        Menu(std::vector<Menu> childs);
    };
}}}

#endif
