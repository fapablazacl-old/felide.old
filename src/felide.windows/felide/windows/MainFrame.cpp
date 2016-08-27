
#include "MainFrame.hpp"

namespace felide { namespace windows {
    MainFrame::MainFrame(const std::map<std::string, std::string> *labels) 
        : m_frame(L"felide::MainFrame"), m_labels(labels) {

        m_frame.Create(L"Test Name", WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    }

    MainFrame::~MainFrame() {}

    void MainFrame::setMenu(const felide::view::gen::Menu &menu) {
        HMENU hMenuBar = ::CreateMenu();

        for (const auto &child : menu.childs) {
            this->generateMenu(hMenuBar, child);
        }

        ::SetMenu(m_frame.GetHandle(), hMenuBar);
    }

    void MainFrame::generateMenu(HMENU &hMenu, const felide::view::gen::Menu &menu) {
        auto labelIterator = m_labels->find(menu.key);

        if (menu.isItem()) {
            if (menu.isSeparator()) {
                ::AppendMenuA(hMenu, MF_SEPARATOR, 1000, NULL);
            } else {
                std::string text = labelIterator->second;

                if (menu.shortcut.key != felide::view::gen::Key::None) {
                    text += "\t" + menu.shortcut.toString();
                }

                ::AppendMenuA(hMenu, MF_STRING, 1000, text.c_str());
            }
        } else {
            std::string text = labelIterator->second;
            HMENU hCurrent = ::CreateMenu();

            for (const auto &childMenu : menu.childs) {
                this->generateMenu(hCurrent, childMenu);
            }

            ::AppendMenuA(hMenu, MF_POPUP, (UINT_PTR)hCurrent, text.c_str());
        }
    }
}}
