
#ifndef __felwin_viewfactory_hpp__
#define __felwin_viewfactory_hpp__

#include <wcl/Application.hpp>
#include <felide/ViewFactory.hpp>

namespace felide { 
    class ViewFactoryWin : public ViewFactory {
    public:
        virtual ~ViewFactoryWin();

        virtual std::unique_ptr<Frame> createMainFrame(const std::map<std::string, std::string> *labels) override;

        virtual std::unique_ptr<Frame> createPluginFrame(PluginManager *pluginManager) override;

        virtual int mainLoop() override;

    private:
        wcl::Application m_app;
    };
}

#endif
