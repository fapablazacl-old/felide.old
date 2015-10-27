
#include "view/win32/CApplication.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	using namespace felide::editor::win32xx;
	
	try {
		CApplication app;
		
		return app.run(0, nullptr);
	} catch (const std::exception &exp) {
		std::string errorMessage = "";
		errorMessage += "Application Error: ";
		errorMessage += exp.what();
		
		::MessageBox(nullptr, errorMessage.c_str(), "Felide Editor", MB_OK | MB_ICONERROR);
		return 1;
	} catch (...) {
		std::string errorMessage = "Unknown error. Please refer to the application logs.";
		
		::MessageBox(nullptr, errorMessage.c_str(), "Felide Editor", MB_OK | MB_ICONERROR);
		return 1;
	}
}
