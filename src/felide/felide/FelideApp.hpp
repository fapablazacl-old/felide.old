
#ifndef __felide_felideapp_hpp__
#define __felide_felideapp_hpp__

#include <map>

#include <felide/Frame.hpp>
#include <felide/Menu.hpp>
#include <felide/Application.hpp>

#include "MainFrameHandler.hpp"

namespace felide {
    class FelideApp : public Application {
    public:
        FelideApp();

        virtual ~FelideApp();

        int run();

    private:
        std::unique_ptr<Frame> m_mainFrame;
        Menu m_mainMenu;
        std::map<std::string, std::string> m_labels_EN;
        MainFrameHandler m_mainHandler;
    };
}

#endif
