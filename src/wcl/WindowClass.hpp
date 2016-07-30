
#pragma once

#ifndef __wcl_windowclass_hpp__
#define __wcl_windowclass_hpp__

#include <Windows.h>
#include <cassert>

namespace wcl {
    
    struct WindowClass : public WNDCLASSEX {
        WindowClass();
        explicit WindowClass(LPWSTR className);
        ~WindowClass();

        ATOM Register();
        BOOL Unregister();
    };

    inline WindowClass::WindowClass() {
        ::ZeroMemory(static_cast<WNDCLASSEX*>(this), sizeof(WNDCLASSEX));

        this->cbSize = sizeof(WNDCLASSEX);
        this->hInstance = ::GetModuleHandle(NULL);
    }
    
    inline WindowClass::WindowClass(LPWSTR className) {
        assert(className);
        assert(className != L"");
        assert(className != std::wstring(L""));
        
        ::ZeroMemory(static_cast<WNDCLASSEX*>(this), sizeof(WNDCLASSEX));

        this->cbSize = sizeof(WNDCLASSEX);
        this->hInstance = ::GetModuleHandle(NULL);
        this->lpszClassName = className;
    }

    inline WindowClass::~WindowClass() {
        BOOL result = this->Unregister();
    }

    inline ATOM WindowClass::Register() {
        assert(this->lpszClassName);
        assert(this->lpszClassName != L"");
        assert(this->lpszClassName != std::wstring(L""));
        
        ATOM atom = ::RegisterClassEx(this);
        
        if (!atom) {
            throw wcl::Exception("Couldn't register the window class");
        }
        
        return atom;
    }
    
    inline BOOL WindowClass::Unregister() {
        if (this->lpszClassName) {
            if (::UnregisterClass(this->lpszClassName, this->hInstance)) {
                ::ZeroMemory(static_cast<WNDCLASSEX*>(this), sizeof(WNDCLASSEX));
            } else {
                throw wcl::Exception("Couldn't unregister the window class");
            }
        }
        
        return TRUE;
    }
}

#endif
