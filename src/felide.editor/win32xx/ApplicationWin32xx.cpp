
#include "ApplicationWin32xx.hpp"

namespace felide { namespace editor { namespace win32xx {
    BOOL ApplicationWin32xx::InitInstance() {
        scintillaModule = std::make_unique<Module>("SciLexer.dll");

        mainFrame.Create();

        return TRUE;
    }
}}}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) {
    felide::editor::win32xx::ApplicationWin32xx app;
    return app.Run();
}
