
#ifndef __felide_editor_dialogfactory_hpp__
#define __felide_editor_dialogfactory_hpp__

#include "Dialog.hpp"
#include <vector>

namespace felide { namespace view {

    enum class DialogIcon {
        Default, Question, Information, Warning, Error
    };

    enum class DialogButton {
        Ok = 1, OkCancel, YesNoCancel
    };

    /**
     * @brief Filter for a file type and its asociated extensions
     */
    struct Filter {
        std::string desc;
        std::vector<std::string> extensions;
    };
    
    class FELIDE_API DialogFactory {
    public:
        virtual ~DialogFactory();
        virtual DialogPtr showMessageDialog(const std::string &title, const std::string &msg, DialogIcon icons, DialogButton buttons) const = 0;
        virtual DialogPtr showInputDialog(const std::string &title, const std::string &msg) const = 0;
        virtual DialogPtr showFileOpenDialog(const std::string &title, const std::vector<Filter> &filters) const = 0;
        virtual DialogPtr showFileSaveDialog(const std::string &title, const std::vector<Filter> &filters) const = 0;
    };

}}

#endif // __felide_editor_dialogfactory_hpp__
