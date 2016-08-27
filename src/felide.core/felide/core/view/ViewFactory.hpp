
#ifndef __felide_core_view_viewfactory_hpp__
#define __felide_core_view_viewfactory_hpp__

#include <memory>
#include <map>
#include <string>
#include <felide/core/PreDef.hpp>

namespace felide { namespace core { namespace view {
    class MainFrame;
    class FELIDE_CORE_API ViewFactory {
    public:
        virtual ~ViewFactory();

        virtual std::unique_ptr<MainFrame> createMainFrame(const std::map<std::string, std::string> *labels) = 0;

        virtual int mainLoop() = 0;
    };
}}}

#endif 
