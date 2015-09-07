
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
		return CFrame::OnCreate(pcs);
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

		MainFrameHandler *handler = this->getHandler();

        switch (command) {
            case ID_FILE_NEW:		handler->handleFileNew();		return TRUE;
            case ID_FILE_OPEN:		handler->handleFileOpen();		return TRUE;
            case ID_FILE_SAVE:		handler->handleFileSave();		return TRUE;
            case ID_FILE_SAVEAS:	handler->handleFileSaveAs();	return TRUE;
            case ID_FILE_EXIT:      handler->handleFileExit();		return TRUE;
			case ID_BUILD_CLEAN:	handler->handleBuildClean();	return TRUE;
			case ID_BUILD_COMPILE:	handler->handleBuildCompile();	return TRUE;
			case ID_BUILD_LINK:		handler->handleBuildLink();		return TRUE;

            default: return FALSE;
        }
    }
	
	Editor* CMainFrame::createEditor(ProjectItemPtr item) {
		CEditor* editor = new CEditor(std::move(item));
		
		this->tabbedMDI.AddMDIChild(WndPtr(editor), editor->getProjectItem()->getName().c_str());

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
}}}
