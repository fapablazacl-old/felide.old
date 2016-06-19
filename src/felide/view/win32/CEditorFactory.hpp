#pragma once

#ifndef __felide_editor_win32xx_ceditorfactory_hpp__
#define __felide_editor_win32xx_ceditorfactory_hpp__

#include <memory>

#include "felide/ProjectItem.hpp"

namespace felide { namespace view { namespace win32xx {
	class CEditor;
	class CEditorFactory {
	public:
		virtual ~CEditorFactory();
		virtual CEditor* createEditor(ProjectItemPtr projectItem) = 0;
	};
	typedef std::unique_ptr<CEditorFactory> CEditorFactoryPtr;
}}}

#endif // __felide_editor_win32xx_ceditorfactory_hpp__
