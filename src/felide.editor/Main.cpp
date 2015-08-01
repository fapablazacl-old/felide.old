
#include "Application.hpp"

int main(int argc, char **argv) {
	int returnCode = 0;

	{
		auto app = felide::editor::Application::new_();
		returnCode = app->run(argc, argv);
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
