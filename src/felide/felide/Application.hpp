
#ifndef __felide_core_application_hpp__
#define __felide_core_application_hpp__

#include <memory>

#include <felide/core/PreDef.hpp>
#include <felide/core/PluginManager.hpp>
#include <felide/core/SystemFactory.hpp>
#include <felide/view/ViewFactory.hpp>

namespace felide {  namespace core {
    class FELIDE_CORE_API Application {
    public:
        Application();
        virtual ~Application();

        PluginManager* getPluginManager();

        SystemFactory* getSystemFactory();

        felide::core::view::ViewFactory* getViewFactory();

        void setViewFactory(felide::core::view::ViewFactory* viewFactory);

    private:
        struct Private;
        Private *m_impl = nullptr;
    };
}}

#endif 
