
#include "MainFrameHandler.hpp"

#include "felide/system/Process.hpp"
#include "MainFrame.hpp"
#include "Editor.hpp"
#include "Dialog.hpp"

#include <boost/variant/get.hpp>

namespace felide { namespace editor {

	namespace fs = boost::filesystem;

	MainFrameHandler::MainFrameHandler(MainFrame *frame) {
	    assert(this);

		this->frame = frame;
	}

	MainFrame* MainFrameHandler::getFrame() {
	    assert(this);

		return this->frame;
	}

	const MainFrame* MainFrameHandler::getFrame() const {
	    assert(this);

		return this->frame;
	}

	bool MainFrameHandler::handleFileNew() {
	    assert(this);

		this->newFileCount++;

		auto item = std::make_unique<ProjectItem>();
		auto editor = this->createEditor(std::move(item));

		this->handleEditorChanged(editor);
        this->getFrame()->updateEnableStatus();

		return true;
	}

    bool MainFrameHandler::handleFileOpen() {
        assert(this);

		auto dialogFactory = this->getFrame()->getDialogFactory();
		auto dialog = dialogFactory->showFileOpenDialog("Open File", "");

		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto item = std::make_unique<ProjectItem>(filePath.string());

		auto editor = this->createEditor(std::move(item));

		this->handleEditorChanged(editor);
		this->getFrame()->updateEnableStatus();

		return true;
	}

    bool MainFrameHandler::handleFileSave(Editor *editor) {
        assert(this);
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
        assert(this);
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
        assert(this);
        
        if (!this->handleFileCloseAll()) {
            return false;
        }
        
		this->getFrame()->close();

		return true;
	}

	bool MainFrameHandler::handleBuildClean() {
	    assert(this);

		return true;
	}

	bool MainFrameHandler::handleBuildCompile() {
	    assert(this);

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
	    assert(this);

		return true;
	}

	bool MainFrameHandler::handleEditorChanged(Editor* editor) {
	    assert(this);
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
	    assert(this);

		MainFrame *frame = this->getFrame();

		for (int i=0; i<frame->getEditorCount(); i++) {
			if (!this->handleFileSave(frame->getEditor(i))) {
				return false;
			}
		}

		return true;
	}

	bool MainFrameHandler::handleFileSave() {
	    assert(this);

		return this->handleFileSave(this->getFrame()->getCurrentEditor());
	}

    bool MainFrameHandler::handleFileSaveAs() {
        assert(this);

		return this->handleFileSaveAs(this->getFrame()->getCurrentEditor());
	}

	bool MainFrameHandler::handleEditUndo() {
	    assert(this);

		this->getFrame()->getCurrentEditor()->undo();
		return true;
	}

	bool MainFrameHandler::handleEditRedo() {
		this->getFrame()->getCurrentEditor()->redo();
		return true;
	}

	bool MainFrameHandler::handleEditCut() {
	    assert(this);

		this->getFrame()->getCurrentEditor()->cut();
		return true;
	}

	bool MainFrameHandler::handleEditCopy() {
	    assert(this);

		this->getFrame()->getCurrentEditor()->copy();
		return true;
	}

	bool MainFrameHandler::handleEditPaste() {
	    assert(this);

		this->getFrame()->getCurrentEditor()->paste();
		return true;
	}

	Editor* MainFrameHandler::createEditor(ProjectItemPtr item) {
	    assert(this);

        Editor* editor = this->getFrame()->createEditor(std::move(item));

		editor->setFont("Courier", 10);
		editor->setTabWidth(4);
		editor->setId(this->newFileCount);

		if (editor->getProjectItem()->hasPath()) {
            editor->setText(editor->getProjectItem()->open());
		}

        return editor;
	}

    bool MainFrameHandler::handleFileClose() {
        assert(this);

        return this->handleFileClose(this->getFrame()->getCurrentEditor());
    }

    bool MainFrameHandler::handleFileClose(Editor *editor) {
        assert(this);
        assert(editor);
        
        // ask for changes
        ProjectItem *item = editor->getProjectItem();
        
        if (item->isModified()) {
            DialogFactory *factory = this->getFrame()->getDialogFactory();
            assert(factory);
            
            const std::string message = "Do you want to save the changes of the file '" + item->getName() + "' ?";
            
            DialogPtr dialog = factory->showMessageDialog("felide.editor", message, DialogIcon::Question, DialogButton::YesNoCancel);
            
            DialogResult result = dialog->getResult();
            
			switch (result) {
				case DialogResult::Yes:
					if (!this->handleFileSave(editor)) {
						return false;
					} 
					break;
					
				case DialogResult::No:
					break;

				case DialogResult::Cancel:
					return false;

				default: assert(false);
			}
        }
        
        this->getFrame()->closeEditor(editor);
        this->getFrame()->updateEnableStatus();
        
        return true;
    }
    
    bool MainFrameHandler::handleFileCloseAll() {
        assert(this);
        
        MainFrame *frame = this->getFrame();
        assert(frame);
        
        for (int i=0; i<frame->getEditorCount(); i++) {
            Editor *editor = frame->getEditor(i);
            assert(editor);
            
            if (!this->handleFileClose(editor)) {
                return false;
            }
        }
        
        return true;
    }
}}
