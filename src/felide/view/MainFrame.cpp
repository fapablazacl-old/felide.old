
#include "MainFrame.hpp"

namespace felide { namespace view {
	MainFrame::MainFrame(DialogFactory *dialogFactory) : View<MainFrameHandler>(dialogFactory) {
        this->setHandler(std::make_unique<MainFrameHandler>(this));
	}

	MainFrame::~MainFrame() {
	}
}}
