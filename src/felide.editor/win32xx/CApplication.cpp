
#include "CApplication.hpp"
#include "CMainFrame.hpp"

namespace felide { namespace editor { namespace win32xx {
	class CApplicationImpl : public CWinApp {
	public:
		virtual BOOL InitInstance() override {
			scintillaModule = std::make_unique<CModule>("SciLexer.dll");
			mainFrame.Create();

			return TRUE;
		}

    private:
        CMainFrame mainFrame;
        CModulePtr scintillaModule;
	};

	int CApplication::run(int argc, char **argv) {
        CApplicationImpl app;
		return app.Run();
	}
}}}
