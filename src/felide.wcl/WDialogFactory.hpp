#pragma once

#include "felide/view/DialogFactory.hpp"

namespace felide { namespace view { namespace win {
    class WDialogFactory : public DialogFactory {
    public:		
	virtual ~WDialogFactory() {}

	virtual DialogPtr showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const override;
	virtual DialogPtr showInputDialog(const std::string &title, const std::string &msg) const override;
	virtual DialogPtr showFileOpenDialog(const std::string &title, const std::vector<Filter> &filters) const override;
	virtual DialogPtr showFileSaveDialog(const std::string &title, const std::vector<Filter> &filters) const override;
    };
}}}
