
#include "CMainFrame.hpp"

#include "CTabbedEditorPanel.hpp"
#include "CEditor.hpp"
#include "felide/system/Process.hpp"
#include "res/resource.h"

#include <file.h>
#include <string>
#include <boost/filesystem.hpp>

namespace felide { namespace editor { namespace win32xx {

    CMainFrame::CMainFrame(DialogFactory *factory) : MainFrame(factory) {
		this->editorPanel = std::make_unique<CTabbedEditorPanel>(this);
        this->SetView(*this->editorPanel.get());
    }
	
	int CMainFrame::OnCreate(LPCREATESTRUCT pcs) {
		assert(this);

		int result = CFrame::OnCreate(pcs);

		return result;
	}

    CMainFrame::~CMainFrame() {}

    void CMainFrame::OnDestroy() {
		assert(this);

        ::PostQuitMessage(0);
    }

    void CMainFrame::OnInitialUpdate() {
		assert(this);

        this->SetWindowTextA("felide.editor");
		this->updateEnableStatus();
    }

    BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) {
		assert(this);

        const int command = LOWORD(wParam);
		const int notification = HIWORD(wParam);

		MainFrameHandler *handler = this->getHandler();

        switch (command) {
            case ID_FILE_NEW:		handler->handleFileNew();		return TRUE;
            case ID_FILE_OPEN:		handler->handleFileOpen();		return TRUE;
            case ID_FILE_SAVE:		handler->handleFileSave();		return TRUE;
            case ID_FILE_SAVEAS:	handler->handleFileSaveAs();	return TRUE;
			case ID_FILE_SAVEALL:	handler->handleFileSaveAll();	return TRUE;
            case ID_FILE_EXIT:      handler->handleFileExit();		return TRUE;
			case ID_BUILD_CLEAN:	handler->handleBuildClean();	return TRUE;
			case ID_BUILD_COMPILE:	handler->handleBuildCompile();	return TRUE;
			case ID_BUILD_LINK:		handler->handleBuildLink();		return TRUE;
			case ID_EDIT_UNDO:		handler->handleEditUndo();		return TRUE;
			case ID_EDIT_REDO:		handler->handleEditRedo();		return TRUE;
			case ID_EDIT_CUT:		handler->handleEditCut();		return TRUE;
			case ID_EDIT_COPY:		handler->handleEditCopy();		return TRUE;
			case ID_EDIT_PASTE:		handler->handleEditPaste();		return TRUE;
        }
		
		return FALSE;
    }
	
	Editor* CMainFrame::createEditor(ProjectItemPtr item) {
		assert(this);

		CEditor* editor = new CEditor(std::move(item));
		
		editor->SetEditorPanel(this->editorPanel.get());

		this->editorPanel->AddMDIChild(WndPtr(editor), editor->getProjectItem()->getName().c_str());

		return editor;
	}

	Editor* CMainFrame::getCurrentEditor() {
		assert(this);

		Editor *editor = dynamic_cast<Editor*>(this->editorPanel->GetActiveMDIChild());

		return editor;
	}

	const Editor* CMainFrame::getCurrentEditor() const {
		assert(this);

		Editor *editor = dynamic_cast<Editor*>(this->editorPanel->GetActiveMDIChild());

		return editor;
	}

	void CMainFrame::close() {
		assert(this);

		CFrame::Close();
	}

	int CMainFrame::getEditorCount() const {
		return this->editorPanel->GetMDIChildCount();
	}

	Editor* CMainFrame::getEditor(const int index) {
		assert(this);
		assert(index >= 0);
		assert(index < this->getEditorCount());

		return dynamic_cast<Editor*>(this->editorPanel->GetMDIChild(index));
	}

	const Editor* CMainFrame::getEditor(const int index) const {
		assert(this);
		assert(index >= 0);
		assert(index < this->getEditorCount());

		return dynamic_cast<Editor*>(this->editorPanel->GetMDIChild(index));
	}

	void CMainFrame::updateEnableStatus() {
		assert(this);

		HMENU menu = this->GetMenuBar()->GetMenu();
		assert(menu);

		const UINT enable = this->getEditorCount()>0?MF_ENABLED:MF_DISABLED;

		int menuItems[] = {
			ID_FILE_SAVE, ID_FILE_SAVEAS, ID_FILE_SAVEALL, ID_FILE_CLOSE, 
			ID_EDIT_UNDO, ID_EDIT_REDO, ID_EDIT_CUT, ID_EDIT_COPY, ID_EDIT_PASTE,
		};

		for (int menuItem : menuItems) {
			::EnableMenuItem(menu, menuItem, enable);
		}
	}

	void CMainFrame::closeEditor(Editor *editor) {
		assert(this);
		assert(editor);

		this->editorPanel->CloseEditor(static_cast<CEditor*>(editor));
	}
}}}
