
#ifndef __felide_editor_mainframe_hpp__
#define __felide_editor_mainframe_hpp__

#include "View.hpp"
#include "MainFrameHandler.hpp"
#include "Editor.hpp"

namespace felide { namespace editor {

	class MainFrameHandler;
	class MainFrame : public View<MainFrameHandler> {
	public:
		MainFrame(DialogFactory *dialogFactory);
		virtual ~MainFrame();

		virtual Editor* createEditor(ProjectItemPtr item) = 0;

		virtual Editor* getCurrentEditor() = 0;
		virtual const Editor* getCurrentEditor() const = 0;

		virtual void close() = 0;
	};
}}

#endif // __felide_editor_mainframe_hpp__
