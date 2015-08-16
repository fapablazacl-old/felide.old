
#include "CEditor.hpp"
#include "CEditorText.hpp"

#if defined(FELIDE_GUI_CODEEDIT_SCI)
#include "EditorSci.hpp"
typedef felide::editor::win32xx::CEditorSci CEditorImpl;
#else 
typedef felide::editor::win32xx::CEditorText CEditorImpl;
#endif 

namespace felide { namespace editor { namespace win32xx {
	CEditor::~CEditor() {} 

	CEditorPtr CEditor::new_(ProjectItemPtr projectItem) {
		return std::unique_ptr<CEditor>(new CEditorImpl(std::move(projectItem)));
	}
}}}
