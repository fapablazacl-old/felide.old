
#include "WindowsGenerator.hpp"

namespace felide { namespace view { namespace gen {

    WindowsGenerator::WindowsGenerator(const std::map<std::string, std::string> *labels, HWND hWnd) 
        : m_labels(labels), m_hWnd(hWnd) {
    }

    void WindowsGenerator::generate(const Menu &menu) {
        HMENU hMenuBar = ::CreateMenu();

        for (const Menu &child : menu.childs) {
            this->generateImpl(hMenuBar, child);
        }

        ::SetMenu(m_hWnd, hMenuBar);
    }

    void WindowsGenerator::generateImpl(HMENU &hMenu, const Menu &menu) {
        auto labelIterator = m_labels->find(menu.key);

        if (menu.isItem()) {
            if (menu.isSeparator()) {
                ::AppendMenuA(hMenu, MF_SEPARATOR, 1000, NULL);
            } else {
                std::string text = labelIterator->second;

                if (menu.shortcut.key != Key::None) {
                    text += "\t" + menu.shortcut.toString();
                }

                ::AppendMenuA(hMenu, MF_STRING, 1000, text.c_str());
            }
        } else {
            std::string text = labelIterator->second;
            HMENU hCurrent = ::CreateMenu();

            for (const Menu &child : menu.childs) {
                this->generateImpl(hCurrent, child);
            }

            ::AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hCurrent, text.c_str());
        }
    }
}}}
