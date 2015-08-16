
#ifndef __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__

#include <map>
#include <functional>
#include <memory>

#include <wincore.h>
#include <frame.h>
#include <mdi.h>
#include <toolbar.h>
#include <tab.h>

#include "CEditor.hpp"
#include "CTabbedEditorPanel.hpp"
#include "felide/ProjectItem.hpp"
#include "felide/system/Process.hpp"

namespace felide { namespace editor { namespace win32xx {

    class CMainFrame : public CFrame {
    public:
        CMainFrame();
        virtual ~CMainFrame();

        virtual void OnDestroy() override;

    protected:
        virtual void OnInitialUpdate() override;
        virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;
        
		virtual int OnCreate(LPCREATESTRUCT pcs) override;

	protected:
		CEditor* getActiveEditor();

        void OnFileNew();
        void OnFileOpen();
        void OnFileSave();
        void OnFileSaveAs();
        void OnFileExit();

		void OnBuildClean();
		void OnBuildCompile();
		void OnBuildLink();

    private:
        bool checkSavedChanges();

    private:
		CTabbedMDI tabbedMDI;
        CEditorPtr textEditor;
    };
}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
