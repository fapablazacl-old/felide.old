
#pragma once

#ifndef __wcl_window_hpp__
#define __wcl_window_hpp__

#include "Rect.hpp"
#include "String.hpp"

#include <Windows.h>
#include <cassert>

namespace wcl {
    
    /**
     * @brief Wrapper for the HWND opaque type.
     */
    class Window {
    protected:
        /**
         * @brief Window Procedure that correctly call the overridable Window::Procedure method and
         * associates the Window pointer to the hWnd, via the USERDATA Window Long.
         */
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
            Window *window = nullptr;

            switch (Msg) {
                case WM_NCCREATE: {
                    auto cs = (CREATESTRUCT*)(lParam);
                    window = (Window*)cs->lpCreateParams;
                    window->m_hWnd = hWnd;
                    window->m_own = true;
                
                    ::SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);

                    return DefWindowProc(hWnd, Msg, wParam, lParam);
                }
                
                default: {
                    window = (Window*)::GetWindowLongPtr(hWnd, GWLP_USERDATA);
                }
            }

            if (window) {
                return window->Procedure(Msg, wParam, lParam);
            } else {
                // Handle System-Level windows messages
                return DefWindowProc(hWnd, Msg, wParam, lParam);
            }
        }

    public:
        static Window MakeReference(HWND hWnd) {
            Window ref;

            ref.Reference(hWnd);

            return ref;
        }

        static Window Make(HWND hWnd) {
            Window window;

            window.Grab(hWnd);

            return window;
        }

        Window() {}

        explicit Window(string className) {
            m_className = className;
        }

        virtual ~Window() {
            if (m_own) {
                this->Destroy();
            }
        }

    public:
        BOOL Create (
            const string &text, 
            DWORD dwStyle, 
            int x = CW_USEDEFAULT, 
            int y = CW_USEDEFAULT, 
            int nWidth = CW_USEDEFAULT, 
            int nHeight = CW_USEDEFAULT, 
            HWND hWndParent = NULL, 
            HMENU hMenu = NULL, 
            HINSTANCE hInstance = ::GetModuleHandle(NULL)) {

            return this->CreateEx(0L, text, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance);
        }

        BOOL CreateEx (
            DWORD dwExStyle,             
            const string &text, 
            DWORD dwStyle, 
            int x = CW_USEDEFAULT, 
            int y = CW_USEDEFAULT, 
            int nWidth = CW_USEDEFAULT, 
            int nHeight = CW_USEDEFAULT, 
            HWND hWndParent = NULL, 
            HMENU hMenu = NULL, 
            HINSTANCE hInstance = ::GetModuleHandle(NULL)) {

            HWND hWnd = ::CreateWindowEx(dwExStyle, m_className.c_str(), text.c_str(), dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, this);
            
            if (!hWnd) {
                return FALSE;
            }

            if (m_hWnd == nullptr) {
                // We are creating a pre registered window, so grab it
                this->Grab(hWnd);
            }

            // Set the default font
            NONCLIENTMETRICS metrics = {};
            metrics.cbSize = sizeof(NONCLIENTMETRICS);
        
            ::SystemParametersInfo(
                SPI_GETNONCLIENTMETRICS,
                sizeof(NONCLIENTMETRICS),
                &metrics, 
                0
            );
        
            HFONT hFont = ::CreateFontIndirect(&metrics.lfMessageFont);
            this->SendMessage_(WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

            return TRUE;
        }

        /**
         * @brief Default window procedure.
         *
         * It automatically calls the original window procedure associated with the Window, and enables the subclassing of 
         * windows with only adding a override. It is very important to call the Window::Procedure at the end of each unhandled 
         * window message.
         */
        virtual LRESULT Procedure(UINT Msg, WPARAM wParam, LPARAM lParam) {
            if (m_wndProc) {
                return m_wndProc(m_hWnd, Msg, wParam, lParam);
            } else {
                // TODO: Handle this case
                return DefWindowProc(m_hWnd, Msg, wParam, lParam);
            }
        }
        
        /**
         * @brief Reference a HWND without taking ownership
         */
        void Reference(HWND hWnd) {
            m_hWnd = hWnd;
            m_own = false;
        }

        /**
         * @brief Take ownership of the supplied HWND
         *
         * Taking ownership of an means replacing the Window Procedure with Window::WndProc and 
         * replacing the USERDATA field with the 'this' pointer.
         */
        void Grab(HWND hWnd) {
            auto ref = Window::MakeReference(hWnd);
            
            // TODO: Define the case when the window already has user data associated.
            LONG_PTR userData = ref.GetLongPtr(GWLP_USERDATA);
            if (userData) {
                
            } 

            m_hWnd = hWnd;
            m_own = true;
            m_wndProc = (WNDPROC)ref.GetLongPtr(GWLP_WNDPROC);

            // check of the m_wndProc is the Window::WndProc.
            // if so, replace it with the DefWindowProc to avoid infinite recursion.
            if (m_wndProc == Window::WndProc) {
                m_wndProc = DefWindowProc;
            }

            ref.SetLongPtr(GWLP_WNDPROC, (LONG_PTR)Window::WndProc);
            ref.SetLongPtr(GWLP_USERDATA, (LONG_PTR)this);
        }

        HWND Release() {
            HWND hWnd = m_hWnd;

            m_hWnd = NULL;

            return hWnd;
        }

        BOOL Close() {
            return ::CloseWindow(m_hWnd);
        }

        BOOL Destroy() {
            if (m_hWnd) {
                BOOL result = ::DestroyWindow(m_hWnd);

                m_hWnd = NULL;

                return result;
            } else {
                return TRUE;
            }
        }

        BOOL Show(int nCmdShow=SW_NORMAL) {
            return ::ShowWindow(m_hWnd, nCmdShow);
        }

        Rect GetClientRect() const {
            Rect rect;

            ::GetClientRect(m_hWnd, &rect);

            return rect;
        }

        BOOL SetPos(HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags) {
            return ::SetWindowPos(m_hWnd, hWndInsertAfter, x, y, cx, cy, uFlags);
        }

        BOOL SetPos(HWND hWndInsertAfter, const Rect &rect, UINT uFlags) {
            return this->SetPos(hWndInsertAfter, rect.left, rect.top, rect.GetWidth(), rect.GetHeight(), uFlags);
        }

        Rect GetRect() const {
            Rect rect = {};

            ::GetWindowRect(m_hWnd, &rect);

            return rect;
        }

        LONG_PTR GetLongPtr(int nIndex) const {
            return ::GetWindowLongPtr(m_hWnd, nIndex);
        }

        LONG_PTR SetLongPtr(int nIndex, LONG_PTR dwNewLong) {
            return ::SetWindowLongPtr(m_hWnd, nIndex, dwNewLong);
        }

        LRESULT SendMessage_(UINT Msg, WPARAM wParam=0L, LPARAM lParam=0L) {
            return ::SendMessage(m_hWnd, Msg, wParam, lParam);
        }

        LRESULT SendMessage_(UINT Msg, WPARAM wParam=0L, LPARAM lParam=0L) const {
            return ::SendMessage(m_hWnd, Msg, wParam, lParam);
        }

        LRESULT PostMessage_(UINT Msg, WPARAM wParam, LPARAM lParam) {
            return ::PostMessage(m_hWnd, Msg, wParam, lParam);
        }

        HDC GetDC() const {
            return ::GetDC(m_hWnd);
        }    

        template<typename Type1, typename Type2>
        LRESULT SendMessage_(UINT Msg, Type1 wParam, Type2 lParam) {
            return this->SendMessage_(Msg, WPARAM(wParam), LPARAM(lParam));
        }

        template<typename Type1>
        LRESULT SendMessage_(UINT Msg, Type1 wParam) {
            return this->SendMessage_(Msg, WPARAM(wParam));
        }

        template<typename Type1, typename Type2>
        LRESULT SendMessage_(UINT Msg, Type1 wParam, Type2 lParam) const {
            return this->SendMessage_(Msg, WPARAM(wParam), LPARAM(lParam));
        }

        template<typename Type1>
        LRESULT SendMessage_(UINT Msg, Type1 wParam) const {
            return this->SendMessage_(Msg, WPARAM(wParam));
        }

        HWND GetHWND() const {
            return m_hWnd;
        }

        void SetText(const std::wstring &text) {
            this->SendMessage_(WM_SETTEXT, 0, text.c_str());
        }

        string GetText() const {
            const LRESULT TEXT_LENGTH = this->SendMessage_(WM_GETTEXTLENGTH);
        
            if (TEXT_LENGTH == 0) {
                return "";
            }

            string text;
            text.resize(TEXT_LENGTH - 1);

            this->SendMessage_(WM_GETTEXT, TEXT_LENGTH, text.c_str());

            return text;
        }

        bool OwnHandle() const {
            return m_own;
        }

        /**
         * @brief Get the parent wrapped as a referece
         */
        Window GetParentRef() const {
            return Window::MakeReference(::GetParent(m_hWnd));
        }

        bool HasParent() const {
            return ::GetParent(m_hWnd) != NULL;
        }

        bool IsWindow() const {
            return ::IsWindow(m_hWnd)==TRUE?true:false;
        }

        bool IsValid() const {
            return m_hWnd != NULL && this->IsWindow();
        }

        /**
         * @brief Test for object identity
         */
        bool operator== (const Window &other) const {
            return m_hWnd == other.m_hWnd;
        }

        bool operator!= (const Window &other) const {
            return !(*this == other);
        }

    protected:
        HWND m_hWnd = NULL;         //! Handle of the Window
        bool m_own = false;         //! True if the hWnd is owned by this window reference. False otherwise.
        WNDPROC m_wndProc = NULL;   //! The original procedure of the Window
        string m_className;         //! Name of the original class used to create the Window
    };
}

#endif
