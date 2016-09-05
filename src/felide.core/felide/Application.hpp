
#ifndef __felide_core_application_hpp__
#define __felide_core_application_hpp__

#include <memory>

#include <felide/PreDef.hpp>
#include <felide/PluginManager.hpp>
#include <felide/ViewFactory.hpp>

namespace felide { 
    class FELIDE_API Application {
    public:
        Application();
        virtual ~Application();

        PluginManager* getPluginManager();

        ViewFactory* getViewFactory();

        void setViewFactory(ViewFactory* viewFactory);

    private:
        struct Private;
        Private *m_impl = nullptr;
    };
}

#endif 
