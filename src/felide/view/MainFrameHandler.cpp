
#include "MainFrameHandler.hpp"

#include "felide/system/Process.hpp"
#include "felide/view/Editor.hpp"
#include "felide/view/Dialog.hpp"
#include "MainFrame.hpp"

#include <boost/variant/get.hpp>

namespace felide { namespace view {

	namespace fs = boost::filesystem;

	bool MainFrameHandler::handleFileNew() {
	    assert(this);

		m_newFileCount++;

		auto item = std::make_unique<ProjectItem>();
		auto view = this->createEditor(std::move(item));

		this->handleEditorChanged(view);
        m_frame->updateEnableStatus();

		return true;
	}

    bool MainFrameHandler::handleFileOpen() {
        assert(this);

		auto dialogFactory = m_frame->getDialogFactory();
		auto dialog = dialogFactory->showFileOpenDialog("Open File", "");

		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto item = std::make_unique<ProjectItem>(filePath.string());

		auto view = this->createEditor(std::move(item));

		this->handleEditorChanged(view);
		m_frame->updateEnableStatus();

		return true;
	}

    bool MainFrameHandler::handleFileSave(Editor *view) {
        assert(this);
		assert(view);

		if (view->getProjectItem()->hasPath()) {
			view->getProjectItem()->save(view->getText());
			this->handleEditorChanged(view);
		} else {
			return this->handleFileSaveAs(view);
		}

		return true;
	}

    bool MainFrameHandler::handleFileSaveAs(Editor *view) {
        assert(this);
		assert(view);

		auto dialogFactory = m_frame->getDialogFactory();
		auto dialog = dialogFactory->showFileSaveDialog("Save File As ...", "");

		if (dialog->getResult() == DialogResult::Cancel) {
			return false;
		}

		auto filePath = boost::get<fs::path>(dialog->getData());
		auto content = view->getText();

		view->getProjectItem()->save(content, filePath.string());
		
		m_frame->setEditorTitle(view, view->getProjectItem()->getName());

		this->handleEditorChanged(view);

		return true;
	}

    bool MainFrameHandler::handleFileExit() {
        assert(this);
        
        if (!this->handleFileCloseAll()) {
            return false;
        }
        
		m_frame->close();

		return true;
	}

	bool MainFrameHandler::handleBuildClean() {
	    assert(this);

		return true;
	}

	bool MainFrameHandler::handleBuildCompile() {
	    assert(this);

		auto dialogFactory = m_frame->getDialogFactory();

		try {
			auto *view = m_frame->getCurrentEditor();
			if (!view) {
				return true;
			}

			auto item = view->getProjectItem();
			if (!item->hasPath() || item->getModifyFlag()) {
				if (!this->handleFileSave(view)) {
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

	bool MainFrameHandler::handleEditorChanged(Editor* view) {
	    assert(this);
		assert(view);

		const ProjectItem* item = view->getProjectItem();

		std::string title = "";

		if (item->hasPath()) {
			title += item->getName();
		} else {
			title += "Untitled " + std::to_string(view->getId());
		}

		title += item->getModifyFlag()?"[*]":"";

		m_frame->setEditorTitle(view, title);

		return true;
	}

	bool MainFrameHandler::handleFileSaveAll() {
	    assert(this);

		MainFrame *frame = m_frame;

		for (int i=0; i<frame->getEditorCount(); i++) {
			if (!this->handleFileSave(frame->getEditor(i))) {
				return false;
			}
		}

		return true;
	}

	bool MainFrameHandler::handleFileSave() {
	    assert(this);

		return this->handleFileSave(m_frame->getCurrentEditor());
	}

    bool MainFrameHandler::handleFileSaveAs() {
        assert(this);

		return this->handleFileSaveAs(m_frame->getCurrentEditor());
	}

	bool MainFrameHandler::handleEditUndo() {
	    assert(this);

		m_frame->getCurrentEditor()->undo();
		return true;
	}

	bool MainFrameHandler::handleEditRedo() {
		m_frame->getCurrentEditor()->redo();
		return true;
	}

	bool MainFrameHandler::handleEditCut() {
	    assert(this);

		m_frame->getCurrentEditor()->cut();
		return true;
	}

	bool MainFrameHandler::handleEditCopy() {
	    assert(this);

		m_frame->getCurrentEditor()->copy();
		return true;
	}

	bool MainFrameHandler::handleEditPaste() {
	    assert(this);

		m_frame->getCurrentEditor()->paste();
		return true;
	}

	Editor* MainFrameHandler::createEditor(ProjectItemPtr item) {
	    assert(this);

        Editor* view = m_frame->createEditor(std::move(item));
        
		view->setFont("Monospace", 10);
		view->setTabWidth(4);
		view->setId(m_newFileCount);

		if (view->getProjectItem()->hasPath()) {
            view->setText(view->getProjectItem()->open());
		}

		view->getProjectItem()->setModifyFlag(false);

        return view;
	}

    bool MainFrameHandler::handleFileClose() {
        assert(this);

        return this->handleFileClose(m_frame->getCurrentEditor());
    }

    bool MainFrameHandler::handleFileClose(Editor *view) {
        assert(this);
        assert(view);
        
        // ask for changes
        ProjectItem *item = view->getProjectItem();
        
        if (item->getModifyFlag()) {
            DialogFactory *factory = m_frame->getDialogFactory();
            assert(factory);
            
            const std::string message = "Do you want to save the changes of the file '" + item->getName() + "' ?";
            
            DialogPtr dialog = factory->showMessageDialog("felide", message, DialogIcon::Question, DialogButton::YesNoCancel);
            
            DialogResult result = dialog->getResult();
            
            if (result == DialogResult::Yes) {
                if (!this->handleFileSave(view)) {
                    return false;
                } 
                
            } else if (result == DialogResult::No) {
                
                
            } else if (result == DialogResult::Cancel) {
                return false;
                
            } else {
                assert(false);
            }
        }
        
        m_frame->closeEditor(view);
        m_frame->updateEnableStatus();
        
        return true;
    }
    
    bool MainFrameHandler::handleFileCloseAll() {
        assert(this);
		assert(m_frame);

        for (int i=0; i<m_frame->getEditorCount(); i++) {
            Editor *view = m_frame->getEditor(i);
            assert(view);
            
            if (!this->handleFileClose(view)) {
                return false;
            }
        }
        
        return true;
    }
}}
