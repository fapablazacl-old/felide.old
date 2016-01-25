
#ifndef __felide_editor_win32xx_cdialogfactory_hpp__
#define __felide_editor_win32xx_cdialogfactory_hpp__

#include "felide/view/DialogFactory.hpp"

namespace felide { namespace editor { namespace win32xx {

	class CDialogFactory : public DialogFactory {
	public:
		virtual ~CDialogFactory();
		virtual DialogPtr showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const override;
		virtual DialogPtr showInputDialog(const std::string &title, const std::string &msg) const override;

		virtual DialogPtr showFileOpenDialog(const std::string &title, const std::string &filters) const override;
		virtual DialogPtr showFileSaveDialog(const std::string &title, const std::string &filters) const override;
	};

}}}

#endif // __felide_editor_win32xx_cdialogfactory_hpp__
