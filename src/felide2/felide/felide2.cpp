
#include <map>

#include <felide/core/view/gen/DefaultGenerator.hpp>
#include <felide/core/view/gen/WindowsGenerator.hpp>
#include <iostream>

#include "Resources.hpp"

#if defined(_WIN32)
#include <Windows.h>
#endif

int main(int argc, char **argv) {
#if defined(_WIN32)
    WNDCLASS wc = {};

    wc.lpszClassName = "Lala";
    wc.lpfnWndProc = DefWindowProc;
    wc.hbrBackground = (HBRUSH)COLOR_3DFACE;
    wc.hCursor = ::LoadCursor(::GetModuleHandle(NULL), IDC_ARROW);
    wc.hIcon = ::LoadIcon(::GetModuleHandle(NULL), IDC_ICON);
    wc.hInstance = ::GetModuleHandle(NULL);

    ::RegisterClass(&wc);

    HWND hWnd = ::CreateWindow("Lala", "Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    felide::view::gen::WindowsGenerator generator(&felide::labels_EN, hWnd);
    generator.generate(felide::mainMenu);

    ShowWindow(hWnd, SW_SHOW);

    MSG msg;

    while (true) {
        if (::PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE) < 0) {
            break;
        } else {
            if (msg.message == WM_QUIT || msg.message == WM_CLOSE) {
                break;
            } else { 
                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
            }
        }
    }

    DestroyWindow(hWnd);

#else 
    Generator generator(labels_EN);
    generator.generate(mainMenu);
#endif

    return EXIT_SUCCESS;
}
