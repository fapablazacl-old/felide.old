
#include "felide/system/Process.hpp"
#include "MainFrame.hpp"
#include "MainFrameHandler.hpp"
#include "Editor.hpp"

#include <boost/variant/get.hpp>

namespace felide { namespace editor {

	namespace fs = boost::filesystem;

	MainFrameHandler::MainFrameHandler(MainFrame *frame) {
		this->frame = frame;
	}
	
	MainFrame* MainFrameHandler::getFrame() {
		return this->frame;
	}

	const MainFrame* MainFrameHandler::getFrame() const {
		return this->frame;
	}

	bool MainFrameHandler::handleFileNew() {
		this->newFileCount++;

		auto item = std::make_unique<ProjectItem>();
		auto editor = this->getFrame()->createEditor(std::move(item));

		editor->setFont("Courier", 8);
		editor->setTabWidth(4);
		editor->setId(this->newFileCount);

		this->handleEditorChanged(editor);

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

		editor->setText(editor->getProjectItem()->open());
		editor->setFont("Courier", 8);
		editor->setTabWidth(4);

		this->handleEditorChanged(editor);

		return true;
	}

    bool MainFrameHandler::handleFileSave(Editor *editor) {
		assert(editor);

		if (editor->getProjectItem()->hasPath()) {
			editor->getProjectItem()->save(editor->getText());
			this->handleEditorChanged(editor);
		} else {
			return this->handleFileSaveAs(editor);
		}

		return true;
	}

    bool MainFrameHandler::handleFileSaveAs(Editor *editor) {
		assert(editor);

		auto dialogFactory = this->getFrame()->getDialogFactory();
		auto dialog = dialogFactory->showFileSaveDialog("Save File As ...", "");

		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto content = editor->getText();

		editor->getProjectItem()->save(content, filePath.string());
		editor->setTitle(editor->getProjectItem()->getName());
		
		this->handleEditorChanged(editor);
		
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
				if (!this->handleFileSave(editor)) {
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

	bool MainFrameHandler::handleEditorChanged(Editor* editor) {
		assert(editor);

		const ProjectItem* item = editor->getProjectItem();

		std::string title = "";

		if (item->hasPath()) {
			title += item->getName();
		} else {
			title += "Untitled " + std::to_string(editor->getId());
		}

		title += item->isModified()?"[*]":"";

		editor->setTitle(title);

		return true;
	}

	bool MainFrameHandler::handleFileSaveAll() {
		MainFrame *frame = this->getFrame();

		for (int i=0; i<frame->getEditorCount(); i++) {
			if (!this->handleFileSave(frame->getEditor(i))) {
				return false;
			}
		}

		return true;
	}

	bool MainFrameHandler::handleFileSave() {
		return this->handleFileSave(this->getFrame()->getCurrentEditor());
	}

    bool MainFrameHandler::handleFileSaveAs() {
		return this->handleFileSaveAs(this->getFrame()->getCurrentEditor());
	}

	bool MainFrameHandler::handleEditUndo() {
		this->getFrame()->getCurrentEditor()->undo();
		return true;
	}

	bool MainFrameHandler::handleEditRedo() {
		this->getFrame()->getCurrentEditor()->redo();
		return true;
	}

	bool MainFrameHandler::handleEditCut() {
		this->getFrame()->getCurrentEditor()->cut();
		return true;
	}

	bool MainFrameHandler::handleEditCopy() {
		this->getFrame()->getCurrentEditor()->copy();
		return true;
	}

	bool MainFrameHandler::handleEditPaste() {
		this->getFrame()->getCurrentEditor()->paste();
		return true;
	}
}}
