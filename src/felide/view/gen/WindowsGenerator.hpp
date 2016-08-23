#pragma once

#ifndef __felide_view_gen_windowsgenerator_hpp__
#define __felide_view_gen_windowsgenerator_hpp__

#include "Generator.hpp"

#include <map>
#include <Windows.h>

namespace felide { namespace view { namespace gen {
    class WindowsGenerator : public Generator {
    public:
        WindowsGenerator(const std::map<std::string, std::string> &labels, HWND hWnd);

        virtual void generate(const Menu &menu) override;

    private:
        void generateImpl(HMENU &hMenu, const Menu &menu);

    private:
        HWND m_hWnd = nullptr;
        std::map<std::string, std::string> m_labels;
    };
}}}

#endif
