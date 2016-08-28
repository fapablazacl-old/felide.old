
#include "MainFrame.hpp"

#include <numeric>
#include <iostream>

namespace felide { namespace windows {

    const int BASE_IDENTIFIER = 1000;

    static int hash(const std::string &key) {
        return std::accumulate(key.begin(), key.end(), static_cast<int>(0));
    }

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

                int identifier = 0;

                // get the command identifier
                auto bimapIterator = m_bimap.left.find(labelIterator->first);
                if (bimapIterator != m_bimap.left.end()) {
                    identifier = bimapIterator->second;
                }

                // get the command text
                std::string text = labelIterator->second;

                if (menu.shortcut.key != felide::view::gen::Key::None) {
                    text += "\t" + menu.shortcut.toString();
                }

                ::AppendMenuA(hMenu, MF_STRING, identifier, text.c_str());
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

        m_bimap.clear();
        for (auto &pair : m_methodMap) {
            const auto key1 = pair.first;
            const auto key2 = BASE_IDENTIFIER + hash(pair.first);

            m_bimap.insert({key1, key2});
        }
    }

    felide::core::view::FrameHandler* MainFrame::getHandler() {
        return m_handler;
    }

    void MainFrame::OnCommand(const int id) {
        auto bimapIterator = m_bimap.right.find(id);

        if (bimapIterator == m_bimap.right.end()) {
            std::clog << "felide::windows::MainFrame::OnCommand: Command identifier " << id << " wasn't found." << std::endl;
            return;
        }

        auto key = bimapIterator->second;

        auto methodIterator = m_methodMap.find(key);
        if (methodIterator == m_methodMap.end()) {
            std::clog << "felide::windows::MainFrame::OnCommand: Command key " << key << " wasn't found." << std::endl;
            return;
        }

        methodIterator->second();
    }
}}
