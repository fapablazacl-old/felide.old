
#include "MainFrame.hpp"

namespace felide { namespace editor {
	MainFrame::MainFrame(DialogFactory *dialogFactory) : 
		View<MainFrameHandler>(dialogFactory) {
	}

	MainFrame::~MainFrame() {
	}
}}
