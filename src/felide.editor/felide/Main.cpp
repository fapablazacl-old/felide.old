
#include "Application.hpp"

int main(int argc, char **argv) {
    return felide::editor::Application::run(argc, argv);
}

#if defined(_WIN32)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) {
	int returnCode = main(0, nullptr);
	return returnCode;
}
#endif
