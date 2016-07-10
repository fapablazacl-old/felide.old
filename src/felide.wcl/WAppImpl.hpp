
#pragma once

#include <wcl/Application.hpp>
#include "felide/App.hpp"
#include "WDialogFactory.hpp"

namespace felide { namespace view { namespace win {
    class WAppImpl : public wcl::Application, public App {
    public:
        WAppImpl();
        virtual ~WAppImpl();

        virtual WDialogFactory* getDialogFactory() {
	    return &m_dialogFactory;
	}

        virtual const WDialogFactory* getDialogFactory() const {
	    return &m_dialogFactory;
	}

        virtual int run(int argc, char **argv) override;

    protected:
	WDialogFactory m_dialogFactory;
    };
}}}
