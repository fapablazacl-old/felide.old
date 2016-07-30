
#include "CMainFrame.hpp"

#include <string>
#include <boost/filesystem.hpp>

#include "wxx_file.h"

#include "felide/system/Process.hpp"
#include "felide/view/win32/CEditor.hpp"

#include "CTabbedEditorPanel.hpp"
#include "res/resource.h"

#if defined(FELIDE_GUI_CODEEDIT_SCI)
#include "felide/view/win32/CEditorSci.hpp"
#include "felide/view/win32/CEditorSciFactory.hpp"

namespace felide { namespace view { namespace win32xx {
	typedef CEditorSciFactory CEditorFactory_Selected;
}}}
	
#else 
#include "felide.editor/win32xx/CEditorText.hpp"
#include "felide.editor/win32xx/CEditorFactoryImpl.hpp"

namespace felide { namespace view { namespace win32xx {
	typedef CEditorFactory<CEditorText> CEditorFactory_Selected;
}}}

#endif

namespace felide { namespace view { namespace win32xx {

    CMainFrame::CMainFrame(DialogFactory *factory) : MainFrame(factory) {

		this->editorFactory = std::make_unique<CEditorFactory_Selected>();

		this->editorPanel = std::make_unique<CTabbedEditorPanel>(this);
        this->SetView(*this->editorPanel.get());
    }
	
	int CMainFrame::OnCreate(CREATESTRUCT &cs) {
		assert(this);

		int result = CFrame::OnCreate(cs);

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
			case ID_FILE_CLOSE:     handler->handleFileClose();		return TRUE;
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
	
	void CMainFrame::OnClose() {
		this->getHandler()->handleFileExit();
	}
	
	Editor* CMainFrame::createEditor(ProjectItemPtr item) {
		assert(this);

		CEditor* editor = this->editorFactory->createEditor(std::move(item));
		
		editor->SetEditorPanel(this->editorPanel.get());

		this->editorPanel->AddMDIChild(editor, editor->getProjectItem()->getName().c_str());

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

		this->CloseWindow();
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

		HMENU menu = this->GetMenuBar().GetMenu();
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

		this->editorPanel->CloseEditor(dynamic_cast<CEditor*>(editor));
	}
	
	void CMainFrame::setEditorTitle(Editor* editor, const std::string &title) {
		CTab &tab = this->editorPanel->GetTab();
		
		const int tabIndex = tab.GetTabIndex(dynamic_cast<CEditor*>(editor));
		tab.SetTabText(tabIndex, title.c_str());
		
		this->editorPanel->RecalcLayout();
	}
	
	std::string CMainFrame::getEditorTitle(Editor* editor) const {
		// TODO: Implement
		return "";
	}
	
	
}}}
