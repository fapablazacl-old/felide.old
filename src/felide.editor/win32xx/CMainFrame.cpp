
#include "CMainFrame.hpp"

#include "CEditor.hpp"
#include "felide/system/Process.hpp"
#include "res/resource.h"

#include <file.h>
#include <string>
#include <boost/filesystem.hpp>

namespace felide { namespace editor { namespace win32xx {

    CMainFrame::CMainFrame(DialogFactory *factory) : MainFrame(factory) {
        this->SetView(this->editorPanel);
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
		const int notification = HIWORD(wParam);

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
        }
		/*
		const HWND hWnd = reinterpret_cast<HWND>(lParam);

		Editor* editor = dynamic_cast<Editor*>(this->editorPanel.GetMDIChildFromHwnd(hWnd));

		if (editor && notification==EN_CHANGE) {
			return TRUE;
		}
		*/
		return FALSE;
    }
	
	Editor* CMainFrame::createEditor(ProjectItemPtr item) {
		CEditor* editor = new CEditor(std::move(item));
		
		editor->SetTabbedMDI(&this->editorPanel);

		this->editorPanel.AddMDIChild(WndPtr(editor), editor->getProjectItem()->getName().c_str());

		return editor;
	}

	Editor* CMainFrame::getCurrentEditor() {
		Editor *editor = dynamic_cast<Editor*>(this->editorPanel.GetActiveMDIChild());

		return editor;
	}

	const Editor* CMainFrame::getCurrentEditor() const {
		Editor *editor = dynamic_cast<Editor*>(this->editorPanel.GetActiveMDIChild());

		return editor;
	}

	void CMainFrame::close() {
		CFrame::Close();
	}
}}}
