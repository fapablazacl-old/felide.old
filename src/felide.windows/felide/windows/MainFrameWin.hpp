
#ifndef __felwin_mainframe_hpp__
#define __felwin_mainframe_hpp__

#include <map>
#include <wcl/Frame.hpp>
#include <felide/Frame.hpp>
#include <felide/FrameHandler.hpp>
#include <boost/bimap.hpp>

namespace felide {

    class MainFrame : public Frame, public wcl::Frame {
    public:
        explicit MainFrame(const std::map<std::string, std::string> *labels);

        virtual ~MainFrame();

        virtual void setMenu(const Menu &menu) override;

        virtual void setHandler(FrameHandler *handler) override;

        virtual FrameHandler* getHandler() override;

    public:
        virtual void OnCommand(const int id) override;

    private:
        void generateMenu(HMENU &hMenu, const Menu &menu);

    private:
        const std::map<std::string, std::string> *m_labels;
        boost::bimap<std::string, int> m_bimap;
        FrameHandler *m_handler;
        HandlerMethodMap m_methodMap;
    };
}

#endif
