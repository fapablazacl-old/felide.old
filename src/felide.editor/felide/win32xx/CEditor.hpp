#pragma once

#ifndef __felide_editor_win32xx_ceditor_hpp__
#define __felide_editor_win32xx_ceditor_hpp__

#include <wincore.h>
#include <memory>

#include "felide.editor/Editor.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CTabbedEditorPanel;
	class CEditor : public virtual Editor, public virtual CWnd {
	public:
		virtual ~CEditor();
		virtual void SetEditorPanel(CTabbedEditorPanel *editorPanel) = 0;
		virtual CTabbedEditorPanel *GetEditorPanel() = 0;
		virtual const CTabbedEditorPanel *GetEditorPanel() const = 0;
	};

	// typedef std::unique_ptr<CEditor> CEditorPtr;
}}}


#endif
