
#include "MainFrame.hpp"

namespace felide { namespace view {
	MainFrame::MainFrame(DialogFactory *dialogFactory) : View<MainFrameHandler>(dialogFactory) {
		m_handler.setFrame(this);
			
	}
	MainFrame::~MainFrame() {}
}}
