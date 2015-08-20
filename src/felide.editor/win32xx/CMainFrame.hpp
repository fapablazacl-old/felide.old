
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

#include "felide/ProjectItem.hpp"
#include "felide/system/Process.hpp"
#include "felide.editor/Editor.hpp"
#include "felide.editor/win32xx/CTabbedEditorPanel.hpp"

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
		Editor* getActiveEditor();
        const Editor* getActiveEditor() const;

        void OnFileNew();
        void OnFileOpen();
        void OnFileSave();
        void OnFileSaveAs();
        void OnFileExit();

		void OnBuildClean();
		void OnBuildCompile();
		void OnBuildLink();

    private:
        bool checkSavedChanges() const;

    private:
		CTabbedMDI tabbedMDI;
        EditorPtr textEditor;
    };
}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
