
#pragma once

#ifndef __felide_view_gen_menu_hpp__
#define __felide_view_gen_menu_hpp__

#include <string>
#include <vector>

namespace felide { namespace view { namespace gen {
    struct Menu {
        std::string key;
        std::vector<Menu> childs;

        Menu();
        Menu(std::string key);
        Menu(std::string key, std::vector<Menu> childs);
        Menu(std::vector<Menu> childs);
    };
}}}

#endif
