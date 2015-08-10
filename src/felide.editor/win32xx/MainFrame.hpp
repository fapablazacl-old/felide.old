
#ifndef __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__

#include <map>
#include <functional>
#include <memory>

#include <wincore.h>
#include <frame.h>
#include <mdi.h>

#include "Editor.hpp"
#include "felide/ProjectItem.hpp"
#include "felide/system/Process.hpp"

namespace felide { namespace editor { namespace win32xx {

    class MainFrame : public CFrame {
    public:
        MainFrame();
        virtual ~MainFrame();

        virtual void OnDestroy() override;

    protected:
        virtual void OnInitialUpdate() override;
        virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;
        
		virtual int OnCreate(LPCREATESTRUCT pcs) override;

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
        EditorPtr textEditor;
        ProjectItemPtr projectItem;

		felide::system::StreamPtr stream;

        /*
        virtual int OnCreate(LPCREATESTRUCT cs) override;
        virtual void SetupToolBar() override;
        virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
        */
    };
}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
