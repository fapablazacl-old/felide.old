
#ifndef __felide_editor_dialog_hpp__
#define __felide_editor_dialog_hpp__

#include <list>
#include <string>
#include <memory>
#include <boost/variant/variant.hpp>
#include <boost/filesystem/path.hpp>

namespace felide { namespace editor {
	enum class DialogResult {
		Cancel,
		Ok
	};

	typedef boost::variant<std::string, boost::filesystem::path> DialogData;
	typedef std::list<DialogData> DialogDataList;

	class Dialog {
	public:
		virtual ~Dialog() {}
		virtual DialogResult getResult() const = 0;
		virtual DialogData getData() const = 0;
		virtual DialogDataList getDataList() const = 0;
	};
	typedef std::unique_ptr<Dialog> DialogPtr;
}}

#endif // __felide_editor_dialog_hpp__
