
#ifndef __felide_editor_mainframe_hpp__
#define __felide_editor_mainframe_hpp__

#include "felide/view/View.hpp"
#include "felide/view/Editor.hpp"

#include "MainFrameHandler.hpp"

namespace felide { namespace editor {

	class MainFrameHandler;
	class FELIDE_API MainFrame : public View<MainFrameHandler> {
	public:
		MainFrame(DialogFactory *dialogFactory);
		virtual ~MainFrame();

		virtual Editor* createEditor(ProjectItemPtr item) = 0;
		virtual void closeEditor(Editor* editor) = 0;

		virtual Editor* getCurrentEditor() = 0;
		virtual const Editor* getCurrentEditor() const = 0;


		virtual int getEditorCount() const = 0;
		virtual Editor* getEditor(const int index) = 0;
		virtual const Editor* getEditor(const int index) const = 0;

		virtual void close() = 0;

		virtual void updateEnableStatus() = 0;
	};
}}

#endif // __felide_editor_mainframe_hpp__
