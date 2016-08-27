
#include <map>

#include "Resources.hpp"

#include <felide/core/Application.hpp>
#include <felide/core/view/MainFrame.hpp>

namespace felide {
    class FelideApp : public felide::core::Application {
    public:
        FelideApp() {
            this->getPluginManager()->load("felide.windows");
        }

        virtual ~FelideApp() {
            this->getPluginManager()->unload("felide.windows");
        }

        int run() {
            m_mainFrame = this->getViewFactory()->createMainFrame(&labels_EN);
            m_mainFrame->setMenu(mainMenu);

            return this->getViewFactory()->mainLoop();
        }

    private:
        std::unique_ptr<felide::core::view::MainFrame> m_mainFrame;
    };
}

int main(int argc, char **argv) {
    felide::FelideApp app;

    return app.run();
}
