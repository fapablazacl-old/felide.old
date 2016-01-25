
#if defined(FELIDE_GUI_CODEEDIT_SCI)

#ifndef __felide_editor_win32xx_ceditorscifactory_hpp__
#define __felide_editor_win32xx_ceditorscifactory_hpp__

#include "CModule.hpp"
#include "CEditorSci.hpp"
#include "CEditorFactoryImpl.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CEditorSciFactory : public CEditorFactoryImpl<CEditorSci> {
	public:
		CEditorSciFactory();
		virtual ~CEditorSciFactory();

	private:
		CModulePtr scintillaModule;
	};
}}}

#endif // __felide_editor_win32xx_ceditorscifactory_hpp__

#endif