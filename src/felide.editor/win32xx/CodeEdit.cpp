
#include "CodeEdit.hpp"
#include "CodeEditText.hpp"

#if defined(FELIDE_GUI_CODEEDIT_SCI)
#include "CodeEditSci.hpp"
typedef felide::editor::win32xx::CodeEditSci CodeEditImpl;
#else 
typedef felide::editor::win32xx::CodeEditText CodeEditImpl;
#endif 

namespace felide { namespace editor { namespace win32xx {
	CodeEdit::~CodeEdit() {} 

	CodeEditPtr CodeEdit::new_() {
		return std::unique_ptr<CodeEdit>(new CodeEditImpl());
	}
}}}
