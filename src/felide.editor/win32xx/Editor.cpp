
#include "Editor.hpp"
#include "EditorText.hpp"

#if defined(FELIDE_GUI_CODEEDIT_SCI)
#include "EditorSci.hpp"
typedef felide::editor::win32xx::CodeEditSci EditorImpl;
#else 
typedef felide::editor::win32xx::EditorText EditorImpl;
#endif 

namespace felide { namespace editor { namespace win32xx {
	Editor::~Editor() {} 

	EditorPtr Editor::new_() {
		return std::unique_ptr<Editor>(new EditorImpl());
	}
}}}
