
#ifndef __felide_editor_mainframe_hpp__
#define __felide_editor_mainframe_hpp__

#include "View.hpp"
#include "MainFrameHandler.hpp"

namespace felide { namespace editor {

	class MainFrameHandler;
	class MainFrame : public View<MainFrameHandler> {
	public:
		explicit MainFrame(MainFrameHandler* handler);

		virtual ~MainFrame();
	};
}}

#endif // __felide_editor_mainframe_hpp__
