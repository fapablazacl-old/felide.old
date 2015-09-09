
#ifndef __felide_editor_mainframehandler_hpp__
#define __felide_editor_mainframehandler_hpp__

namespace felide { namespace editor {

	class MainFrame;
	class Editor;
	class MainFrameHandler {
	public:
		explicit MainFrameHandler(MainFrame *frame);

		bool handleFileNew();
        bool handleFileOpen();
        bool handleFileSave();
        bool handleFileSaveAs();
        bool handleFileExit();

		bool handleBuildClean();
		bool handleBuildCompile();
		bool handleBuildLink();

		bool handleEditorTitleUpdated(Editor* editor);

	public:
		MainFrame* getFrame();

		const MainFrame* getFrame() const;

	private:
		MainFrame *frame = nullptr;
		int newFileCount = 0;
	};
}}

#endif // __felide_editor_mainframecontroller_hpp__
