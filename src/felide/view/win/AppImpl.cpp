
#include "AppImpl.hpp"
#include "WMainFrame.hpp"

namespace felide { namespace view { namespace win {

	AppImpl::AppImpl() {

		// Load another win32 controls here
		this->Load("SciLexer.dll");
	}

	AppImpl::~AppImpl() {}

	int AppImpl::run(int argc, char **argv) {
		WMainFrame frame(this);

		std::string title = this->getTitle();

		frame.Create(std::wstring(title.begin(), title.end()), WS_OVERLAPPEDWINDOW);
		frame.Show();

		return this->Run();
	}
}}}

namespace felide {
	App* App::getInstance() {
		static felide::view::win::AppImpl app;
		return &app;
	}
}
