
#include "AppImpl.hpp"
#include "MainFrameImpl.hpp"

#include <QDockWidget>

namespace felide { namespace view { namespace qt5 {

    int AppImpl::run(int argc, char **argv) {
        ::QApplication app(argc, argv);
        
        MainFrameImpl mainFrame(&m_dialogFactory);
        mainFrame.show();

        return app.exec();    
    }
    

}}}

namespace felide {    
    App* App::getInstance() {
        static felide::view::qt5::AppImpl app;
        
        return &app;
    }
}
