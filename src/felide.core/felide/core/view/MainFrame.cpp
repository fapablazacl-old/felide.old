
#include "MainFrame.hpp"

namespace felide { namespace core { namespace view {
    MainFrame::~MainFrame() {}

    Editor* MainFrame::appendEditor() {
        return this->appendEditor(this->getEditorCount());
    }
}}}
