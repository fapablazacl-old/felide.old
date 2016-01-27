
#ifndef __felide_editor_mainframehandler_hpp__
#define __felide_editor_mainframehandler_hpp__

#include "felide/ProjectItem.hpp"

namespace felide { namespace editor {

	class MainFrame;
	class Editor;

	class FELIDE_API MainFrameHandler {
	public:
		explicit MainFrameHandler(MainFrame *frame);

		bool handleFileNew();
        bool handleFileOpen();
        bool handleFileSave(Editor* editor);
        bool handleFileSaveAs(Editor* editor);

		bool handleFileSave();
        bool handleFileSaveAs();

		bool handleFileSaveAll();

		bool handleFileClose();
		bool handleFileClose(Editor *editor);
        bool handleFileCloseAll();
        
        bool handleFileExit();

		bool handleBuildClean();
		bool handleBuildCompile();
		bool handleBuildLink();

		bool handleEditorChanged(Editor* editor);

		bool handleEditUndo();
		bool handleEditRedo();

		bool handleEditCut();
		bool handleEditCopy();
		bool handleEditPaste();

    protected:
        Editor* createEditor(ProjectItemPtr item);

	public:
		MainFrame* getFrame();

		const MainFrame* getFrame() const;

	private:
		MainFrame *frame = nullptr;
		int newFileCount = 0;
	};
}}

#endif // __felide_editor_mainframecontroller_hpp__