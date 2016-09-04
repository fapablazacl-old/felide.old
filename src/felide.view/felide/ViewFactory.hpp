
#ifndef __felide_core_view_viewfactory_hpp__
#define __felide_core_view_viewfactory_hpp__

#include <memory>
#include <map>
#include <string>
#include <felide/PreDef.hpp>

namespace felide {
    class Frame;
    class FELIDE_CORE_API ViewFactory {
    public:
        virtual ~ViewFactory();

        virtual std::unique_ptr<Frame> createMainFrame(const std::map<std::string, std::string> *labels) = 0;

        virtual int mainLoop() = 0;
    };
}

#endif 
