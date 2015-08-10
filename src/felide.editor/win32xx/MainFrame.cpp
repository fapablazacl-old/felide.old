
#include "MainFrame.hpp"
#include "felide/system/Process.hpp"
#include "res/resource.h"

#include <file.h>
#include <string>
#include <boost/filesystem.hpp>

namespace felide { namespace editor { namespace win32xx {

	class SimpleStream : public felide::system::Stream {
	public:
		SimpleStream(Editor *editor) {
			this->editor = editor;
		}

		virtual void write(const char *str) {
			this->editor->SetText(CString(str));
		}

	private:
		Editor *editor = nullptr;
	};

    MainFrame::MainFrame() {
        this->projectItem = std::make_unique<ProjectItem>();

        this->textEditor = Editor::new_();
        this->SetView(*this->textEditor->getWindow());
    }

	int MainFrame::OnCreate(LPCREATESTRUCT pcs) {
		int result = CFrame::OnCreate(pcs);

		this->textEditor->setFont("Courier", 10);
		this->textEditor->setTabWidth(4);

		this->stream = std::make_unique<SimpleStream>(this->textEditor.get());

		return result;
	}

    MainFrame::~MainFrame() {}

    void MainFrame::OnDestroy() {
        ::PostQuitMessage(0);
    }

    void MainFrame::OnInitialUpdate() {
        this->SetWindowTextA("felide.editor");
    }

    BOOL MainFrame::OnCommand(WPARAM wParam, LPARAM lParam) {
        const int command = LOWORD(wParam);

        switch (command) {
            case ID_FILE_NEW:       this->OnFileNew();      return TRUE;
            case ID_FILE_OPEN:      this->OnFileOpen();     return TRUE;
            case ID_FILE_SAVE:      this->OnFileSave();     return TRUE;
            case ID_FILE_SAVEAS:    this->OnFileSaveAs();   return TRUE;
            case ID_FILE_EXIT:      this->OnFileExit();     return TRUE;

			case ID_BUILD_CLEAN:	this->OnBuildClean();	return TRUE;
			case ID_BUILD_COMPILE:	this->OnBuildCompile();	return TRUE;
			case ID_BUILD_LINK:		this->OnBuildLink();	return TRUE;

            default: return FALSE;
        }
    }

    bool MainFrame::checkSavedChanges() {
        if (this->projectItem->isModified()) {
            int result = MessageBox("Do you want to save the changes?", "Felide", MB_YESNOCANCEL | MB_ICONQUESTION);

            switch (result) {
                case 0: 
                    this->SendMessage(WM_COMMAND, ID_FILE_SAVE, 0); 
                    return true;

                case 1: return true;
                case 2: return false;
            }
        }

        return true;
    }

    void MainFrame::OnFileNew() {
        if (!this->checkSavedChanges()) {
            return;
        }

        this->projectItem = std::make_unique<ProjectItem>();

        this->textEditor->ClearAll();
        this->textEditor->EmptyUndoBuffer();
    }

    void MainFrame::OnFileOpen() {
        CString filePath = CFile().OpenFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");
                
        if (filePath == "") {
            return;
        }

        this->SendMessage(WM_COMMAND, ID_FILE_NEW, 0);

        std::string content = this->projectItem->open(filePath.c_str());

        this->textEditor->SetText(content.c_str());
        this->textEditor->EmptyUndoBuffer();
        this->textEditor->SetSavePoint();
    }

    void MainFrame::OnFileSave() {
        if (!this->projectItem->hasPath()) {
            this->SendMessage(WM_COMMAND, ID_FILE_SAVEAS, 0);
            return;
        }

        std::string content = this->textEditor->GetText().c_str();
        this->projectItem->save(content);
    }

    void MainFrame::OnFileSaveAs() {
        CString filePath = CFile().SaveFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");

        if (filePath == "") {
            return;
        }

        std::string content = this->textEditor->GetText().c_str();
        this->projectItem->save(content, filePath.c_str());
    }

    void MainFrame::OnFileExit() {
        if (!this->checkSavedChanges()) {
            return;
        }

        this->Close();
    }

	void MainFrame::OnBuildClean() {}

	void MainFrame::OnBuildCompile() {
		try {
			if (!this->projectItem->hasPath()) {
				this->MessageBox("Save the source first", "felide.editor", MB_OK | MB_ICONEXCLAMATION);
				return;
			}

			namespace fs = boost::filesystem;

			fs::path path = this->projectItem->getPath();
			fs::path parentPath = path.parent_path().string();

			// setup command line parameters
			std::list<std::string> args = {
				this->projectItem->getPath(),
				"-o" + (parentPath / path.stem()).string() + ".exe",
				"-O0", 
				"-Wall",
				"-lstdc++"
			};

			auto compiler = felide::system::Process::open("gcc", args);
			compiler->start();
			compiler->wait();
		} catch (std::exception &exp) {
			::MessageBox(NULL, exp.what(), "Error", MB_OK | MB_ICONERROR);
		}
	}

	void MainFrame::OnBuildLink() {

	}
}}}
