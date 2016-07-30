
#ifndef __felide_editor_dialog_hpp__
#define __felide_editor_dialog_hpp__

#include <list>
#include <string>
#include <memory>
#include <boost/variant/variant.hpp>
#include <boost/filesystem/path.hpp>

#include "felide/Predef.hpp"

namespace felide { namespace view {
    enum class DialogResult {
        Cancel, Ok, Yes, No
    };

    typedef boost::variant<std::string, boost::filesystem::path> DialogData;
    typedef std::list<DialogData> DialogDataList;

    class FELIDE_API Dialog {
    public:
        virtual ~Dialog();
        virtual DialogResult getResult() const = 0;
        virtual DialogData getData() const = 0;
        virtual DialogDataList getDataList() const = 0;
    };
    typedef std::unique_ptr<Dialog> DialogPtr;
}}

#endif // __felide_editor_dialog_hpp__
