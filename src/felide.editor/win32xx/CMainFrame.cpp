
#include "CMainFrame.hpp"

#include "CEditor.hpp"
#include "felide/system/Process.hpp"
#include "res/resource.h"

#include <file.h>
#include <string>
#include <boost/filesystem.hpp>

namespace felide { namespace editor { namespace win32xx {

    CMainFrame::CMainFrame(DialogFactory *factory) : MainFrame(factory) {
        this->SetView(this->tabbedMDI);
    }
	
	int CMainFrame::OnCreate(LPCREATESTRUCT pcs) {
		int result = CFrame::OnCreate(pcs);

		/*
		this->textEditor->setFont("Courier", 10);
		this->textEditor->setTabWidth(4);
		*/

		return result;
	}

    CMainFrame::~CMainFrame() {}

    void CMainFrame::OnDestroy() {
        ::PostQuitMessage(0);
    }

    void CMainFrame::OnInitialUpdate() {
        this->SetWindowTextA("felide.editor");
    }

    BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) {
        const int command = LOWORD(wParam);

        switch (command) {
            case ID_FILE_NEW:		this->handler->handleFileNew();			return TRUE;
            case ID_FILE_OPEN:		this->handler->handleFileOpen();		return TRUE;
            case ID_FILE_SAVE:		this->handler->handleFileSave();		return TRUE;
            case ID_FILE_SAVEAS:	this->handler->handleFileSaveAs();		return TRUE;
            case ID_FILE_EXIT:      this->handler->handleFileExit();		return TRUE;
			case ID_BUILD_CLEAN:	this->handler->handleBuildClean();		return TRUE;
			case ID_BUILD_COMPILE:	this->handler->handleBuildCompile();	return TRUE;
			case ID_BUILD_LINK:		this->handler->handleBuildLink();		return TRUE;

            default: return FALSE;
        }
    }
	
  //  void CMainFrame::OnFileNew() {
  //      auto projectItem = std::make_unique<ProjectItem>();

  //      Editor *editor = Editor::new_(std::move(projectItem));

  //      CWnd *editorCtrl = dynamic_cast<CWnd*>(editor);

  //      // WndPtr textEditor(editorCtrl);
  //      
  //      editorCtrl->Create(&this->tabbedMDI);

  //      this->tabbedMDI.AddMDIChild(WndPtr(editorCtrl), "Lala");

  //      /*
		//Editor *editor = this->getCurrentEditor();
		//editor->getProjectItem()->new_();
  //      editor->clearAll();
  //      editor->emptyUndoBuffer();
  //      */
  //  }

  //  void CMainFrame::OnFileOpen() {
  //      CString filePath = CFile().OpenFileDialog(nullptr, 6UL, nullptr, "C/C++ Files\0*.c;*.cpp");
  //              
  //      if (filePath == "") {
  //          return;
  //      }

		//Editor *editor = this->getCurrentEditor();

  //      this->SendMessage(WM_COMMAND, ID_FILE_NEW, 0);

  //      std::string content = editor->getProjectItem()->open(filePath.c_str());

  //      editor->setText(content.c_str());
  //      editor->emptyUndoBuffer();
  //      editor->setSavePoint();
  //  }
	
	Editor* CMainFrame::createEditor(ProjectItemPtr item) {
		CEditor* editor = new CEditor(std::move(item));

		this->tabbedMDI.AddMDIChild(WndPtr(editor), "Test01");

		return editor;
	}

	Editor* CMainFrame::getCurrentEditor() {
		return this->textEditor.get();
	}

	const Editor* CMainFrame::getCurrentEditor() const {
		return this->textEditor.get();
	}

	void CMainFrame::close() {
		CFrame::Close();
	}

	void CMainFrame::setHandler(MainFrameHandler *handler) {
		this->handler = handler;
	}

	MainFrameHandler* CMainFrame::getHandler() {
		return this->handler;
	}

	const MainFrameHandler* CMainFrame::getHandler() const {
		return this->handler;
	}
}}}
