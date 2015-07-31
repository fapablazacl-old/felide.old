
/*
#include <QApplication>
#include "qt5/MainWindow.hpp"

int main(int argc, char **argv) {
    ::QApplication app(argc, argv);
    
    felide::qt5::MainWindow mainWindow;
    
    mainWindow.show();
    
    return app.exec();
}
*/

#include "Application.hpp"

int main(int argc, char **argv) {
	int returnCode = 0;

	{
		auto app = felide::editor::Application::new_();
		returnCode = app->getReturnCode();
	}
	
    return returnCode;
}

#if defined(_WIN32)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) {
	int returnCode = main(0, nullptr);
	return returnCode;
}
#endif
