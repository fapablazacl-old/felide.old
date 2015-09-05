
#include "felide/system/Process.hpp"
#include "MainFrame.hpp"
#include "MainFrameHandler.hpp"

#include <boost/variant/get.hpp>

namespace felide { namespace editor {

	namespace fs = boost::filesystem;

	MainFrameHandler::MainFrameHandler(MainFrame *frame) {
		this->frame = frame;
	}
	
	bool MainFrameHandler::handleFileNew() {
		auto item = std::make_unique<ProjectItem>();
		auto editor = this->getFrame()->createEditor(std::move(item));

		editor->setFont("Courier", 8);
		editor->setTabWidth(4);

		return true;
	}

    bool MainFrameHandler::handleFileOpen() {
		auto dialogFactory = this->getFrame()->getDialogFactory();
		auto dialog = dialogFactory->showFileOpenDialog("Open File", "");
		
		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto item = std::make_unique<ProjectItem>(filePath.string());
		auto editor = this->getFrame()->createEditor(std::move(item));

		editor->setTitle(editor->getProjectItem()->getName());
		editor->setText(editor->getProjectItem()->open());
		editor->setFont("Courier", 8);
		editor->setTabWidth(4);

		return true;
	}

    bool MainFrameHandler::handleFileSave() {
		Editor* editor = this->getFrame()->getCurrentEditor();

		if (!editor) {
			return true;
		}

		if (!editor->getProjectItem()->hasPath()) {
			return this->handleFileSaveAs();
		}

		editor->getProjectItem()->save(editor->getText());

		return true;
	}

    bool MainFrameHandler::handleFileSaveAs() {
		auto editor = this->getFrame()->getCurrentEditor();

		if (!editor) {
			return true;
		}

		auto dialogFactory = this->getFrame()->getDialogFactory();
		auto dialog = dialogFactory->showFileSaveDialog("Save File As ...", "");

		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto content = editor->getText();

		editor->getProjectItem()->save(content, filePath.string());

		return true;
	}

    bool MainFrameHandler::handleFileExit() {
		this->getFrame()->close();

		return true;
	}

	bool MainFrameHandler::handleBuildClean() {
		return true;
	}

	bool MainFrameHandler::handleBuildCompile() {
		auto dialogFactory = this->getFrame()->getDialogFactory();

		try {
			auto *editor = this->getFrame()->getCurrentEditor();
			if (!editor) {
				return true;
			}

			auto item = editor->getProjectItem();
			if (!item->hasPath() || item->isModified()) {
				if (!this->handleFileSave()) {
					return false;
				}
			}

			namespace fs = boost::filesystem;

			fs::path path = item->getPath();
			fs::path parentPath = path.parent_path().string();

			// setup command line parameters
			std::list<std::string> args = {
				item->getPath(),
				"-o" + (parentPath / path.stem()).string() + ".exe",
				"-O0",
				"-Wall",
				"-lstdc++"
			};

			namespace felsys = felide::system;

			auto compiler = felsys::Process::open(felsys::ProcessFlags::Redirect, "gcc", args);
			compiler->start();
			compiler->wait();

			std::string dialogMsg;
			DialogIcon dialogIcon;

			if (compiler->getExitCode() != 0) {
				dialogMsg = compiler->getOutput();
				dialogIcon = DialogIcon::Error;
			} else {
				dialogMsg = "Compilation OK";
				dialogIcon = DialogIcon::Information;
			}

			dialogFactory->showMessageDialog("felide.editor", dialogMsg, dialogIcon, DialogButton::Ok);

		} catch (std::exception &exp) {
			dialogFactory->showMessageDialog(
				"felide.editor", 
				"Runtime Error" + std::string(exp.what()), 
				DialogIcon::Error, 
				DialogButton::Ok
			);
		}

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
