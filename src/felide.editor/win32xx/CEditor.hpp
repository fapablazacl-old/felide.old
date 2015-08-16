
#ifndef __felide_editor_win32xx_editor_hpp__
#define __felide_editor_win32xx_editor_hpp__

#include <memory>
#include <wincore.h>

#include "felide/ProjectItem.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CEditor;
	typedef std::unique_ptr<CEditor> CEditorPtr;

	class CEditor {
	public:
		virtual ~CEditor();

        virtual void SetText(const CString &text) = 0;
        virtual CString GetText() = 0;

        virtual void SetSavePoint() = 0;
        virtual void EmptyUndoBuffer() = 0;
        virtual void ClearAll() = 0;
		virtual void setTabWidth(const int spaces) = 0;

		// Underlying window
		virtual CWnd* getWindow() = 0;
		virtual void setFont(const CString &name, const int size) = 0;

		virtual ProjectItem* getProjectItem() = 0;
		virtual const ProjectItem* getProjectItem() const = 0;

	public:
		static CEditorPtr new_(ProjectItemPtr item);
	};
}}}

#endif	// __felide_editor_win32xx_editor_hpp__
