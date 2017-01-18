
#include "WinApplication.hpp"
#include "WinMainFrame.hpp"

#include <wcl/Application.hpp>

namespace felide {
    WinApplication::WinApplication() {}

    WinApplication::~WinApplication() {}

    int WinApplication::run(int argc, char **argv) {
        wcl::Application app;

        WinMainFrame mainFrame;

        BOOL result = mainFrame.Create(L"Hola, Mundo!", WS_OVERLAPPEDWINDOW);
        mainFrame.Show(SW_NORMAL);

        return app.Run();
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    felide::WinApplication app;

    return app.run(0, nullptr);
}
