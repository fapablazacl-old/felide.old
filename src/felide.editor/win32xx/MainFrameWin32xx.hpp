
#ifndef __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
#define __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__

#include <map>
#include <functional>
#include <memory>

#include <wincore.h>
#include <frame.h>
#include <mdi.h>

#include "ScintillaWin32xx.hpp"
#include "felide/ProjectItem.hpp"

namespace felide { namespace editor { namespace win32xx {

    class MainFrameWin32xx : public CFrame {
    public:
        MainFrameWin32xx();
        virtual ~MainFrameWin32xx();

        virtual void OnDestroy() override;

    protected:
        virtual void OnInitialUpdate() override;
        virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;
        
        void OnFileNew();
        void OnFileOpen();
        void OnFileSave();
        void OnFileSaveAs();
        void OnFileExit();
        
    private:
        bool checkSavedChanges();

    private:
        std::unique_ptr<Scintilla> textEditor;
        std::unique_ptr<ProjectItem> projectItem;

        /*
        virtual int OnCreate(LPCREATESTRUCT cs) override;
        virtual void SetupToolBar() override;
        virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
        */
    };
}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
