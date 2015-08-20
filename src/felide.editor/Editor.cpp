
#include "Editor.hpp"

#if defined(FELIDE_GUI_TOOLKIT_WIN32XX)

#if defined(FELIDE_GUI_CODEEDIT_SCI)
#include "felide.editor/win32xx/CEditorSci.hpp"
typedef felide::editor::win32xx::CEditorSci CEditorImpl;
#else 
#include "felide.editor/win32xx/CEditorText.hpp"
typedef felide::editor::win32xx::CEditorText CEditorImpl;
#endif 

namespace felide { namespace editor {
    Editor* Editor::new_(ProjectItemPtr projectItem) {
        return new CEditorImpl(std::move(projectItem));
    }
}}

#endif 
