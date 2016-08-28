
#include "MainFrame.hpp"

#include <numeric>
#include <iostream>

namespace felide { namespace windows {

    const int BASE_IDENTIFIER = 1000;

    MainFrame::MainFrame(const std::map<std::string, std::string> *labels) 
        : wcl::Frame(L"felide::MainFrame"), m_labels(labels) {

        this->Create(L"Test Name", WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    }

    MainFrame::~MainFrame() {}

    void MainFrame::setMenu(const felide::view::gen::Menu &menu) {
        HMENU hMenuBar = ::CreateMenu();

        for (const auto &child : menu.childs) {
            this->generateMenu(hMenuBar, child);
        }

        ::SetMenu(this->GetHandle(), hMenuBar);
    }

    void MainFrame::generateMenu(HMENU &hMenu, const felide::view::gen::Menu &menu) {
        auto labelIterator = m_labels->find(menu.key);

        if (menu.isItem()) {
            if (menu.isSeparator()) {
                ::AppendMenuA(hMenu, MF_SEPARATOR, 0, NULL);
            } else {
                const auto keyIterator = std::find(m_keys.begin(), m_keys.end(), labelIterator->first);
                const int identifier = keyIterator - m_keys.begin();

                std::string text = labelIterator->second;

                if (menu.shortcut.key != felide::view::gen::Key::None) {
                    text += "\t" + menu.shortcut.toString();
                }

                ::AppendMenuA(hMenu, MF_STRING, BASE_IDENTIFIER + identifier, text.c_str());
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

    void MainFrame::setHandler(felide::core::view::FrameHandler *handler) {
        m_handler = handler;
        m_methodMap = handler->buildMap();

        m_keys.clear();
        for (auto &pair : m_methodMap) {
            m_keys.push_back(pair.first);
        }
    }

    felide::core::view::FrameHandler* MainFrame::getHandler() {
        return m_handler;
    }

    void MainFrame::OnCommand(const int id) {
        const int index = id - BASE_IDENTIFIER;
        if (index < 0  || index >= m_keys.size()) {
            std::clog << "felide::windows::MainFrame::OnCommand: Command identifier " << index << " wasn't found." << std::endl;
            return;
        }

        const std::string key = m_keys[index];
        auto methodIterator = m_methodMap.find(key);

        if (methodIterator == m_methodMap.end()) {
            std::clog << "felide::windows::MainFrame::OnCommand: Command key " << key << " wasn't found." << std::endl;
            return;
        }

        methodIterator->second();
    }
}}
