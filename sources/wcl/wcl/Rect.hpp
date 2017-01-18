
#pragma once

#ifndef __wcl_rect_hpp__
#define __wcl_rect_hpp__

#include <Windows.h>

namespace wcl {
    /**
     * Wrapper structure around RECT structure
     */
    struct Rect : public RECT {
        Rect() {
            ::ZeroMemory(this, sizeof(Rect));
        }

        Rect(int left, int top, int right, int bottom) {
            this->left = left;
            this->top = top;
            this->right = right;
            this->bottom = bottom;
        }

        int GetWidth() const {
            return this->right - this->left;
        }

        int GetHeight() const {
            return this->bottom - this->top;
        }

        bool IsValid() const {
            return this->GetWidth() <= 0 || this->GetHeight() <= 0;
        }
    };
}

#endif
