
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
#include "felide.editor/MainFrame.hpp"
#include "felide.editor/win32xx/CEditorFactory.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel;
    class CMainFrame : public CFrame, public MainFrame {
    public:
        explicit CMainFrame(DialogFactory *factory);
        virtual ~CMainFrame();

        virtual void OnDestroy() override;

	public:
		virtual Editor* createEditor(ProjectItemPtr item) override;
		virtual Editor* getCurrentEditor() override;
		virtual const Editor* getCurrentEditor() const override;
		virtual void closeEditor(Editor *editor) override;
		virtual void close() override;

		virtual int getEditorCount() const override;
		virtual Editor* getEditor(const int index) override;
		virtual const Editor* getEditor(const int index) const override;

		virtual void updateEnableStatus() override;

    protected:
        virtual void OnInitialUpdate() override;
        virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;
		virtual int OnCreate(LPCREATESTRUCT pcs) override;
		
    private:
		std::unique_ptr<CTabbedEditorPanel> editorPanel;
		CEditorFactoryPtr editorFactory;
    };
}}}

#endif  // __FELIDE_EDITOR_WIN32XX_MAINFRAMEWIN32XX_HPP__
