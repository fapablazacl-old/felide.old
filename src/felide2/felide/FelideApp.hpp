
#ifndef __felide_felideapp_hpp__
#define __felide_felideapp_hpp__

#include <map>

#include <felide/core/Application.hpp>
#include <felide/core/view/MainFrame.hpp>
#include <felide/core/view/gen/Menu.hpp>
#include <felide/core/view/gen/Generator.hpp>

namespace felide {
    class FelideApp : public felide::core::Application {
    public:
        FelideApp();

        virtual ~FelideApp();

        int run();

    private:
        std::unique_ptr<felide::core::view::MainFrame> m_mainFrame;
        felide::view::gen::Menu m_mainMenu;
        std::map<std::string, std::string> m_labels_EN;
    };
}

#endif
