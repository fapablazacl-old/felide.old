
#include "Menu.hpp"

namespace felide {
    MenuBar::MenuBar(const std::initializer_list<Menu> menues) 
        : m_menues(menues) {}

    const std::vector<Menu>& MenuBar::getMenues() const {
        return m_menues;
    }
}

namespace felide {
    Menu::Menu() {}

    Menu::Menu(const std::string &key, const std::vector<Menu> &childs) 
        : m_key(key), m_childs(childs) {}
    
    Menu Menu::item(const std::string &key) {
        return Menu(key, {});
    }

    Menu Menu::separator() {
        Menu menu;

        menu.m_separator = true;

        return menu;
    }

    bool Menu::isSeparator() const {
        return m_separator;
    }

    std::string Menu::getKey() const {
        return m_key;
    }

    const std::vector<Menu>& Menu::getChilds() const {
        return m_childs;
    }
}
