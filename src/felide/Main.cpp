
#include <wx/app.h>
#include <felide/interface/MainWindow.hpp>

class Application : public wxApp {
public:
	virtual bool OnInit() {
		using felide::gui::MainWindow;
		
		MainWindow *window = new MainWindow();

		window->Show();

		return true;
	}
};

wxDECLARE_APP(Application);
wxIMPLEMENT_APP(Application);
