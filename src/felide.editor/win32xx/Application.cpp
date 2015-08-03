
#include "Application.hpp"

namespace felide { namespace editor { namespace win32xx {
	class ApplicationImpl : public CWinApp {
	public:
		virtual BOOL InitInstance() override {
			scintillaModule = std::make_unique<Module>("SciLexer.dll");
			mainFrame.Create();

			return TRUE;
		}

    private:
        MainFrame mainFrame;
        ModulePtr scintillaModule;
	};

	int Application::run(int argc, char **argv) {
		ApplicationImpl app;
		return app.Run();
	}
}}}
