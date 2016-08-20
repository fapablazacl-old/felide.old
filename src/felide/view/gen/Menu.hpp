
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
    
    enum class Modifier {
        None,
        Control,
        Shift,
        Control_Shift = Control + Shift
    };

    enum class Key {
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        N1, N2, N3, N4, N5, N6, N7, N8, N9, N0
    };

    struct Shortcut {
        Modifier modifier;
        Key key;

        Shortcut() {}
        Shortcut(Key key_) : key(key_) {}
        Shortcut(Modifier modifier_, Key key_) : modifier(modifier_), key(key_) {}
    };

    struct Menu {
        std::string key;
        Shortcut shortcut;
        MenuStatus status = MenuStatus::Unchecked;
        std::vector<Menu> childs;

        Menu();
        Menu(std::string key);
        Menu(std::string key, MenuStatus status);

        Menu(std::string key, Shortcut shortcut);

        Menu(std::string key, Shortcut shortcut, MenuStatus status);

        //Menu(std::string key, std::string shortcut);
        Menu(std::string key, std::vector<Menu> childs);
        Menu(std::vector<Menu> childs);
    };
}}}

#endif
