
#ifndef __felwin_viewfactory_hpp__
#define __felwin_viewfactory_hpp__

#include <wcl/Application.hpp>
#include <felide/view/ViewFactory.hpp>

namespace felide { namespace windows {
    class ViewFactory : public felide::core::view::ViewFactory {
    public:
        virtual ~ViewFactory();

        virtual std::unique_ptr<felide::core::view::Frame> createMainFrame(const std::map<std::string, std::string> *labels) override;

        virtual int mainLoop() override;

    private:
        wcl::Application m_app;
    };
}}

#endif
