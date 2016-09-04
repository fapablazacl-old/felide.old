#pragma once

#ifndef __felide_view_gen_hpp__
#define __felide_view_gen_hpp__

#include <string>
#include <felide/PreDef.hpp>

namespace felide {
    enum class Modifier {
        None = 0,
        Control = 1,
        Shift = 2,
        Alt = 4,
        Control_Shift = Control + Shift,
        Control_Alt = Control + Alt,
        Shift_Alt = Shift + Alt,
        Control_Shift_Alt = Control + Shift + Alt
    };

    inline bool operator& (Modifier modifiers, Modifier modifier) {
        if (static_cast<int>(modifiers) & static_cast<int>(modifier)) {
            return true;
        } else {
            return false;
        }
    }

    enum class Key {
        None,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        N1, N2, N3, N4, N5, N6, N7, N8, N9, N0
    };

    struct FELIDE_CORE_API Shortcut {
        Modifier modifier = Modifier::None;
        Key key = Key::None;

        Shortcut() {}
        Shortcut(Key key_) : key(key_) {}
        Shortcut(Modifier modifier_, Key key_) : modifier(modifier_), key(key_) {}

        std::string toString() const;
    };
}

#endif
