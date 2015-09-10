
#ifndef __felide_editor_qt5_qapplication_hpp__
#define __felide_editor_qt5_qapplication_hpp__

#include "felide.editor/Application.hpp"
#include "felide.editor/qt5/QDialogFactory.hpp"

namespace felide { namespace editor { namespace qt5 {

    class QApplication : public felide::editor::Application {
    public:
        QApplication();
    
        virtual void initialize(int argc, char **argv) override;
        virtual int execute(int argc, char **argv) override;
        
    private:
        QDialogFactory dialogFactory;
    };
}}}

#endif  // __felide_editor_qt5_application_hpp__
