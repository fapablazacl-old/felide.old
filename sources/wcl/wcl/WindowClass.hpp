
#pragma once

#ifndef __wcl_windowclass_hpp__
#define __wcl_windowclass_hpp__

#include <Windows.h>
#include <cassert>

namespace wcl {
    /**
     * Wrapper around WNDCLASSEX
     */
    struct WindowClass : WNDCLASSEX {
    public:
        static WindowClass MakeDefault(LPTSTR className, WNDPROC wndProc) {
            return {
                className, 
                wndProc,
                (HBRUSH)(COLOR_BTNFACE + 1),
                ::LoadCursor(GetModuleHandle(NULL), IDC_ARROW),
                ::LoadIcon(GetModuleHandle(NULL), IDI_APPLICATION)
            };
        }

    public:
        WindowClass() {
            ::ZeroMemory(this, sizeof(WNDCLASSEX));

            cbSize = sizeof(WNDCLASSEX);
            hInstance = ::GetModuleHandle(NULL);
        }

        WindowClass(LPTSTR className, WNDPROC wndProc=NULL, HBRUSH hBrushBackground=NULL, HICON hIcon=NULL, HCURSOR hCursor=NULL) : WindowClass() {
            lpszClassName = className;
            lpfnWndProc = wndProc;
            hbrBackground = hBrushBackground;
            this->hIcon = hIcon;
            this->hCursor = hCursor;
        }

        ~WindowClass() {
            this->Unregister();
        }

        BOOL Register() {
            if (::RegisterClassEx((const WNDCLASSEX*)this)) {
                return TRUE;
            } else {
                return FALSE;
            }
        }

        BOOL Unregister() {
            return ::UnregisterClass(lpszClassName, hInstance);
        }
    };
}

#endif
