
#ifndef __felide_editor_qt5_qapplication_hpp__
#define __felide_editor_qt5_qapplication_hpp__

#include "felide/App.hpp"
#include "DialogFactoryImpl.hpp"

namespace felide { namespace view { namespace qt5 {
    class AppImpl : public App {
    public:
        virtual int run(int argc, char **argv) override;
        
        virtual felide::view::DialogFactory* getDialogFactory() override {
            return &m_dialogFactory;
        }
        
        virtual const felide::view::DialogFactory* getDialogFactory() const override {
            return &m_dialogFactory;
        }
        
    private:
        DialogFactoryImpl m_dialogFactory;
    };
}}}

#endif  // __felide_editor_qt5_application_hpp__
