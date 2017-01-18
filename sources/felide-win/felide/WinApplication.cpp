
#include "WinApplication.hpp"
#include "WinMainFrame.hpp"

#include <wcl/Application.hpp>

namespace felide {
    WinApplication::WinApplication() {
        WinMainFrame::GetWindowClass()->Register();
    }

    WinApplication::~WinApplication() {}

    int WinApplication::run(int argc, char **argv) {
        wcl::Application app;

        WinMainFrame mainFrame;

        BOOL result = mainFrame.Create("Hola, Mundo!", WS_OVERLAPPEDWINDOW);
        mainFrame.Show();

        return app.Run();
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    felide::WinApplication app;

    return app.run(0, nullptr);
}
