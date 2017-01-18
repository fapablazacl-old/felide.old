
#include "WinApplication.hpp"

namespace felide {
    WinApplication::WinApplication() {}

    WinApplication::~WinApplication() {}
}


#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBox(NULL, "", "", MB_OK);

    return 0;
}
