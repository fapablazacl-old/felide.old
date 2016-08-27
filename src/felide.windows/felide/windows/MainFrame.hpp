
#ifndef __felwin_mainframe_hpp__
#define __felwin_mainframe_hpp__

#include <map>
#include <felide/core/view/MainFrame.hpp>
#include <wcl/Frame.hpp>

namespace felide { namespace windows {

    class MainFrame {
    public:
        explicit MainFrame(const std::map<std::string, std::string> *labels);

        virtual ~MainFrame();

        virtual void setMenu(const felide::view::gen::Menu &menu);

    private:
        void generateMenu(HMENU &hMenu, const felide::view::gen::Menu &menu);

    private:
        wcl::Frame m_frame;
        const std::map<std::string, std::string> *m_labels;
    };
}}

#endif
