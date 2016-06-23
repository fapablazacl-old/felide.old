
#ifndef __felide_editor_mainframehandler_hpp__
#define __felide_editor_mainframehandler_hpp__

#include "felide/ProjectItem.hpp"

namespace felide { namespace view {

	class MainFrame;
	class Editor;

	class FELIDE_API MainFrameHandler {
	public:
		MainFrameHandler() {}
		explicit MainFrameHandler(MainFrame *frame) : m_frame(frame) {}

		bool handleFileNew();
        bool handleFileOpen();
        bool handleFileSave(Editor* view);
        bool handleFileSaveAs(Editor* view);

		bool handleFileSave();
        bool handleFileSaveAs();

		bool handleFileSaveAll();

		bool handleFileClose();
		bool handleFileClose(Editor *view);
        bool handleFileCloseAll();
        
        bool handleFileExit();

		bool handleBuildClean();
		bool handleBuildCompile();
		bool handleBuildLink();

		bool handleEditorChanged(Editor* view);

		bool handleEditUndo();
		bool handleEditRedo();

		bool handleEditCut();
		bool handleEditCopy();
		bool handleEditPaste();

    protected:
        Editor* createEditor(ProjectItemPtr item);

	public:
		MainFrame* getFrame() {
			return m_frame;
		}

		const MainFrame* getFrame() const {
			return m_frame;
		}

		void setFrame(MainFrame *frame) {
			m_frame = frame;
		}

	private:
		MainFrame *m_frame = nullptr;
		int m_newFileCount = 0;
	};
}}

#endif // __felide_editor_mainframecontroller_hpp__
