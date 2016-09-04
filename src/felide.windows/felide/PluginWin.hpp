
#ifndef __felwin_pluginwin_hpp__
#define __felwin_pluginwin_hpp__

#include <map>
#include <felide/Plugin.hpp>

#include "ViewFactory.hpp"

namespace felide { 
    class PluginWin : public Plugin {
    public:
        PluginWin();

        ~PluginWin();

        virtual PluginData getData() const override;

        virtual void start(Application *application) override;

        virtual void stop(Application *application) override;

    private:
        ViewFactory m_viewFactory;
    };
}

#endif
