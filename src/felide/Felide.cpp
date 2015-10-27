

#include <felide/Application.hpp>
#include <felide/system/Library.hpp>

int main(int argc, char **argv) {
	/*
	using felide::Application;
	using felide::system::LibraryPtr;
	
	LibraryPtr library = Library::load(argv[1]);
	ApplicationPtr app = Application::load(library);
	
	return app.execute(argc, argv);
	*/
	return 0;
}

#if defined(_WINDOWS)
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR lpCmdLine, UINT nCmdShow) {
	return ::main(0, nullptr);
}
#else 

#endif
