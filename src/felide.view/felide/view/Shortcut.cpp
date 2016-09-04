
#include "Shortcut.hpp"

#include <map>
#include <list>
#include <boost/algorithm/string/join.hpp>

namespace felide { namespace view { namespace gen {

    static std::map<Key, std::string> keyString = {
        {Key::F1, "F1"},
        {Key::F2, "F2"},
        {Key::F3, "F3"},
        {Key::F4, "F4"},
        {Key::F5, "F5"},
        {Key::F6, "F6"},
        {Key::F7, "F7"},
        {Key::F8, "F8"},
        {Key::F9, "F9"},
        {Key::F10, "F10"},
        {Key::F11, "F11"},
        {Key::F12, "F12"},
        {Key::A, "A"},
        {Key::B, "B"},
        {Key::C, "C"},
        {Key::D, "D"},
        {Key::E, "E"},
        {Key::F, "F"},
        {Key::G, "G"},
        {Key::H, "H"},
        {Key::I, "I"},
        {Key::J, "J"},
        {Key::K, "K"},
        {Key::L, "L"},
        {Key::M, "M"},
        {Key::N, "N"},
        {Key::O, "O"},
        {Key::P, "P"},
        {Key::Q, "Q"},
        {Key::R, "R"},
        {Key::S, "S"},
        {Key::T, "T"},
        {Key::U, "U"},
        {Key::V, "V"},
        {Key::W, "W"},
        {Key::X, "X"},
        {Key::Y, "Y"},
        {Key::Z, "Z"},
        {Key::N1, "1"},
        {Key::N2, "2"},
        {Key::N3, "3"},
        {Key::N4, "4"},
        {Key::N5, "5"},
        {Key::N6, "6"},
        {Key::N7, "7"},
        {Key::N8, "8"},
        {Key::N9, "9"},
        {Key::N0, "0"}
    };

    static std::map<Modifier, std::string> modifierString = {
        {Modifier::Control, "Ctrl"}, 
        {Modifier::Shift, "Shift"}, 
        {Modifier::Alt, "Alt"}
    };

    std::string Shortcut::toString() const {
        std::string result;

        std::list<std::string> elements;

        for (const auto &pair : modifierString) {
            if (modifier & pair.first) {
                elements.push_back(pair.second);
            }
        }

        elements.push_back(keyString[key]);

        result = boost::join(elements, "+");

        return result;
    }
}}}
