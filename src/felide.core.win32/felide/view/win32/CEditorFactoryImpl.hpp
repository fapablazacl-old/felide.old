#pragma once

#ifndef __felide_editor_win32xx_ceditorfactoryimpl_hpp__
#define __felide_editor_win32xx_ceditorfactoryimpl_hpp__

#include "CEditorFactory.hpp"

namespace felide { namespace editor { namespace win32xx {

	template<class CEditorClass>
	class CEditorFactoryImpl : public CEditorFactory {
	public:
		virtual ~CEditorFactoryImpl() {}

		virtual CEditor* createEditor(ProjectItemPtr projectItem) override {
			return new CEditorClass(std::move(projectItem));
		}
	};
}}}

#endif
