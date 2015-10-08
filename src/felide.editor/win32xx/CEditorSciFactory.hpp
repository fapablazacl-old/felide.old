#pragma once

#ifndef __felide_editor_win32xx_ceditorscifactory_hpp__
#define __felide_editor_win32xx_ceditorscifactory_hpp__

#include "felide.editor/win32xx/CModule.hpp"
#include "felide.editor/win32xx/CEditorSci.hpp"
#include "felide.editor/win32xx/CEditorFactoryImpl.hpp"

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
