
#ifndef __felide_editor_win32xx_codeedittext_hpp__
#define __felide_editor_win32xx_codeedittext_hpp__

#include <wincore.h>

#include "CodeEdit.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CodeEditText : public CodeEdit {
	public:
		virtual ~CodeEditText();

		virtual void PreCreate(CREATESTRUCT &cs) override;

		virtual void SetText(const CString &text) override;
        virtual CString GetText() override;

        virtual void SetSavePoint() override;
        virtual void EmptyUndoBuffer() override;
        virtual void ClearAll() override;
	};
}}}

#endif	// __felide_editor_win32xx_codeedit_hpp__
