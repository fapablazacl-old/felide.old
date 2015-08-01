
#ifndef __felide_application_hpp__
#define __felide_application_hpp__

#include <memory>

namespace felide { namespace editor {

	class Application;
	typedef std::unique_ptr<Application> ApplicationPtr;

	class Application {
	public:
		virtual ~Application();
		virtual int getReturnCode() = 0;

	public:
		static ApplicationPtr new_();
	};
}}

#endif	// __felide_application_hpp__
