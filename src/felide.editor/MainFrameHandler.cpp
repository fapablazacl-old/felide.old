

#include "MainFrame.hpp"
#include "MainFrameHandler.hpp"

namespace felide { namespace editor {

	MainFrameHandler::MainFrameHandler(MainFrame *frame) {
		this->frame = frame;
	}

	bool MainFrameHandler::handleFileNew() {
		return true;
	}

    bool MainFrameHandler::handleFileOpen() {
		return true;
	}

    bool MainFrameHandler::handleFileSave() {
		return true;
	}

    bool MainFrameHandler::handleFileSaveAs() {
		return true;
	}

    bool MainFrameHandler::handleFileExit() {
		return true;
	}

	bool MainFrameHandler::handleBuildClean() {
		return true;
	}

	bool MainFrameHandler::handleBuildCompile() {
		return true;
	}

	bool MainFrameHandler::handleBuildLink() {
		return true;
	}

	MainFrame* MainFrameHandler::getFrame() {
		return this->frame;
	}

	const MainFrame* MainFrameHandler::getFrame() const {
		return this->frame;
	}
}}
