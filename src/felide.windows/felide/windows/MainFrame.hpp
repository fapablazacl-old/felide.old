
#ifndef __felwin_mainframe_hpp__
#define __felwin_mainframe_hpp__

#include <map>
#include <wcl/Frame.hpp>
#include <felide/core/view/MainFrame.hpp>
#include <felide/core/view/FrameHandler.hpp>
#include <boost/bimap.hpp>

namespace felide { namespace windows {

    class MainFrame : public felide::core::view::MainFrame, public wcl::Frame {
    public:
        explicit MainFrame(const std::map<std::string, std::string> *labels);

        virtual ~MainFrame();

        virtual void setMenu(const felide::view::gen::Menu &menu) override;

        virtual void setHandler(felide::core::view::FrameHandler *handler) override;

        virtual felide::core::view::FrameHandler* getHandler() override;

    public:
        virtual void OnCommand(const int id) override;

    private:
        void generateMenu(HMENU &hMenu, const felide::view::gen::Menu &menu);

    private:
        const std::map<std::string, std::string> *m_labels;
        boost::bimap<std::string, int> m_bimap;
        felide::core::view::FrameHandler *m_handler;
        felide::core::view::HandlerMethodMap m_methodMap;
    };
}}

#endif
