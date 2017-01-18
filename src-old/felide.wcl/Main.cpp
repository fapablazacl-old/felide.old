//
//#include <string>
//
//#include "WMainFrame.hpp"
//#include "IdeApp.hpp"
//
//// int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow) {
//int main() {
//	
//	try {
//		IdeApp app;
//		
//		WMainFrame frame(&app);
//		
//		frame.Create(L"wcl::IDE", WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL);
//		frame.Show(SW_NORMAL);
//		
//		app.SetWindowAccelerator(frame.GetHandle(), frame.GetAcceleratorTable()->GetHandle());
//
//		return app.Run();
//	} catch (const wcl::Exception &e) {
//		MessageBoxA(NULL, e.what(), "Designer - Windows Exception", MB_OK|MB_ICONERROR);
//
//		return 1;
//	} catch (const std::exception &e) {
//		MessageBoxA(NULL, e.what(), "Designer - C++ Exception", MB_OK|MB_ICONERROR);
//
//		return 2;
//	} catch (...) {
//		MessageBoxA(NULL, "Unknown fatal error", "Designer - C++ Exception", MB_OK|MB_ICONERROR);
//
//		return 3;
//	}
//}
