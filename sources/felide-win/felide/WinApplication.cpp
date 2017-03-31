
#include "WinApplication.hpp"
#include "WinMainFrame.hpp"

#include <wcl/Application.hpp>

#include <vector>

namespace felide {
    struct Menu {
        std::string text;
        std::vector<Menu> childs;

        static Menu Separator() {

        }

        static Menu Item(const std::string &text) {
            
        }

        static Menu SubMenu(const std::string &text, const std::vector<Menu> &childs) {

        }
    };

    struct MenuBar {
        std::vector<Menu> childs;

        MenuBar() {}

        MenuBar(const std::initializer_list<Menu> &menues_) 
            : childs(std::begin(menues_), std::end(menues_)) {}
    };
}

namespace felide {

    MenuBar menuBar = {
        {"&File", {
            {"&New ..."}, 
            {"&New ..."}, 
            {"&New ..."}, 
            {"&New ..."}, 
            {"&New ..."}
        }}
    };

    WinApplication::WinApplication() {
        WinMainFrame::GetWindowClass()->Register();
    }

    WinApplication::~WinApplication() {}

    int WinApplication::run(int argc, char **argv) {
        wcl::Application app;

        WinMainFrame mainFrame;

        BOOL result = mainFrame.Create("felide", WS_OVERLAPPEDWINDOW);
        mainFrame.Show();

        return app.Run();
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    felide::WinApplication app;

    return app.run(0, nullptr);
}
