
#ifndef __FELIDE_EDITOR_APPLICATION_HPP__
#define __FELIDE_EDITOR_APPLICATION_HPP__

#include <memory>

namespace felide { namespace editor {
	class Application {
	public:
        virtual ~Application() {}
		virtual int run(int argc, char **argv) = 0;

    public:
        static std::unique_ptr<Application> new_();
	};
}}

#endif	// __FELIDE_EDITOR_APPLICATION_HPP__
