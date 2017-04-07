
#pragma once

#ifndef __felide_menu_hpp__
#define __felide_menu_hpp__

#include <string>
#include <vector>
#include <initializer_list>

namespace felide {
    class Menu;

    class MenuBar {
    public:
        explicit MenuBar(const std::initializer_list<Menu> menues);

        const std::vector<Menu>& getMenues() const;

    public:
        std::vector<Menu> m_menues;
    };

    class Menu {
    public:
        Menu();

        Menu(const std::string &key, const std::vector<Menu> &childs);

        bool isSeparator() const;

        std::string getKey() const;

        static Menu item(const std::string &key);

        static Menu separator();

        const std::vector<Menu>& getChilds() const;

    private:
        std::string m_key;
        bool m_separator = false;
        std::vector<Menu> m_childs;
    };
}

#endif
