
#ifndef __felide_core_view_framehandler_hpp__
#define __felide_core_view_framehandler_hpp__

#include <map>
#include <functional>
#include <felide/core/PreDef.hpp>

namespace felide { namespace core { namespace view {
    typedef std::function<void()> HandlerMethod;
    typedef std::map<std::string, HandlerMethod> HandlerMethodMap;

    class FELIDE_CORE_API FrameHandler {
    public:
        virtual ~FrameHandler();
        virtual HandlerMethodMap buildMap() = 0;
    };
}}}

#endif
