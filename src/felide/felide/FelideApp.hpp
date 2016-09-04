
#ifndef __felide_felideapp_hpp__
#define __felide_felideapp_hpp__

#include <map>

#include <felide/view/Frame.hpp>
#include <felide/view/Menu.hpp>

#include "Application.hpp"
#include "MainFrameHandler.hpp"

namespace felide {
    class FelideApp : public felide::core::Application {
    public:
        FelideApp();

        virtual ~FelideApp();

        int run();

    private:
        std::unique_ptr<felide::core::view::Frame> m_mainFrame;
        felide::view::gen::Menu m_mainMenu;
        std::map<std::string, std::string> m_labels_EN;
        MainFrameHandler m_mainHandler;
    };
}

#endif
