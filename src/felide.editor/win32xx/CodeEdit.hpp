
#ifndef __felide_editor_win32xx_editor_hpp__
#define __felide_editor_win32xx_editor_hpp__

#include <memory>
#include <wincore.h>

namespace felide { namespace editor { namespace win32xx {

	class CodeEdit;
	typedef std::unique_ptr<CodeEdit> CodeEditPtr;

	class CodeEdit {
	public:
		virtual ~CodeEdit();

        virtual void SetText(const CString &text) = 0;
        virtual CString GetText() = 0;

        virtual void SetSavePoint() = 0;
        virtual void EmptyUndoBuffer() = 0;
        virtual void ClearAll() = 0;
		virtual void setTabWidth(const int spaces) = 0;

		// Underlying window
		virtual CWnd* getWindow() = 0;
		virtual void setFont(const CString &name, const int size) = 0;

	public:
		static CodeEditPtr new_();
	};
}}}

#endif	// __felide_editor_win32xx_editor_hpp__
