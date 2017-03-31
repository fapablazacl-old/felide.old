
#if defined(FELIDE_GUI_CODEEDIT_SCI)

#include "CEditorSciFactory.hpp"
#include "CModule.hpp"

namespace felide { namespace view { namespace win32xx {
	CEditorSciFactory::CEditorSciFactory() {
		const char SCINTILLA_DLL_NAME[] = "SciLexer.dll";
		this->scintillaModule = std::make_unique<CModule>(SCINTILLA_DLL_NAME);
	}

	CEditorSciFactory::~CEditorSciFactory() {}
}}}

#endif
