
#include "CApplication.hpp"
#include "CMainFrame.hpp"
#include "CDialogFactory.hpp"

namespace felide { namespace editor { namespace win32xx {
	class CApplicationImpl : public CWinApp {
	public:
		CApplicationImpl() {
			this->dialogFactory = std::make_unique<CDialogFactory>();
			this->mainFrame = std::make_unique<CMainFrame>(this->dialogFactory.get());
		}

		virtual BOOL InitInstance() override {
			mainFrame->Create();

			return TRUE;
		}

    private:
		std::unique_ptr<CDialogFactory> dialogFactory;
		std::unique_ptr<CMainFrame> mainFrame;
	};

	int CApplication::execute(int argc, char **argv) {
        CApplicationImpl app;
		return app.Run();
	}
}}}
