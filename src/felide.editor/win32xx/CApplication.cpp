
#include "CApplication.hpp"
#include "CMainFrame.hpp"
#include "CDialogFactory.hpp"

namespace felide { namespace editor { namespace win32xx {
	class CApplicationImpl : public CWinApp {
	public:
		CApplicationImpl() {
			this->dialogFactory = std::make_unique<CDialogFactory>();
			this->mainFrame = std::make_unique<CMainFrame>(this->dialogFactory.get());
			this->mainFrameHandler = std::make_unique<MainFrameHandler>(this->mainFrame.get());

			this->mainFrame->setHandler(this->mainFrameHandler.get());
		}

		virtual BOOL InitInstance() override {
			scintillaModule = std::make_unique<CModule>("SciLexer.dll");
			mainFrame->Create();

			return TRUE;
		}

    private:
		std::unique_ptr<CDialogFactory> dialogFactory;
		std::unique_ptr<MainFrameHandler> mainFrameHandler;
		std::unique_ptr<CMainFrame> mainFrame;
        CModulePtr scintillaModule;
	};

	int CApplication::run(int argc, char **argv) {
        CApplicationImpl app;
		return app.Run();
	}
}}}
