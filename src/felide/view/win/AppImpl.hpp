
#pragma once

#include <wcl/Application.hpp>
#include "felide/App.hpp"

namespace felide { namespace view { namespace win {
	class AppImpl : public wcl::Application, public App {
	public:
		AppImpl();
		virtual ~AppImpl();

		virtual int run(int argc, char **argv) override;
	};
}}}
