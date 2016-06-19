
#include <iostream>

#if defined(FELIDE_VIEW_QT5)
#include <felide/view/qt5/QApplication.hpp>
typedef felide::view::qt5::QApplication App;
#endif 

#if defined(FELIDE_VIEW_WIN32)
#include <felide/view/win32/CApplication.hpp>
typedef felide::view::win32xx::CApplication App;
#endif 

int main(int argc, char **argv) {
	return App().run(argc, argv);
}
