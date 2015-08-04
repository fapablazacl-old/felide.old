
#ifndef __felide_editor_win32xx_codeedittext_hpp__
#define __felide_editor_win32xx_codeedittext_hpp__

#include <wincore.h>
#include <stdcontrols.h>

#include "CodeEdit.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CodeEditText : public CodeEdit {
	public:
		CodeEditText();
		virtual ~CodeEditText();

		virtual CWnd* getWindow() override;

		virtual void SetText(const CString &text) override;
        virtual CString GetText() override;

        virtual void SetSavePoint() override;
        virtual void EmptyUndoBuffer() override;
        virtual void ClearAll() override;

		virtual void setTabWidth(const int spaces) override;

	private:
		std::unique_ptr<CEdit> edit;
	};
}}}

#endif	// __felide_editor_win32xx_codeedit_hpp__
