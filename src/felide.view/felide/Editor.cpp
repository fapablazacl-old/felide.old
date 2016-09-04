
#include "Editor.hpp"
#include "Frame.hpp"

namespace felide {
    Editor::Editor(MainFrame *mainFrame) 
        : m_mainFrame(mainFrame) {}

    Editor::~Editor() {}
/*
    std::size_t Editor::getIndex() const {
        for (std::size_t i=0; i<m_mainFrame->getEditorCount(); i++) {
            if (this == m_mainFrame->getEditor(i)) {
                return i;
            }
        }

        return -1;
    }*/
}
