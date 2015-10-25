
#ifndef __felide_editor_dialogfactory_hpp__
#define __felide_editor_dialogfactory_hpp__

#include "Dialog.hpp"

namespace felide { namespace editor {

	enum class DialogIcon {
		Default,
        Question, 
		Information,
		Warning,
		Error
	};

	enum class DialogButton {
		Ok = 1,
		OkCancel,
        YesNoCancel
	};

	class DialogFactory {
	public:
		virtual ~DialogFactory() {}
		virtual DialogPtr showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const = 0;
		virtual DialogPtr showInputDialog(const std::string &title, const std::string &msg) const = 0;
		virtual DialogPtr showFileOpenDialog(const std::string &title, const std::string &filters) const = 0;
		virtual DialogPtr showFileSaveDialog(const std::string &title, const std::string &filters) const = 0;
	};

}}

#endif // __felide_editor_dialogfactory_hpp__
