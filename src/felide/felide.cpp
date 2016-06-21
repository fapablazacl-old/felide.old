//
//#include <iostream>
//
//#if defined(FELIDE_VIEW_QT5)
//#include <felide/view/qt5/QApplication.hpp>
//typedef felide::view::qt5::QApplication App;
//#endif 
//
//#if defined(FELIDE_VIEW_WIN32)
//
//#endif 
//

#include "felide/App.hpp"

int main(int argc, char **argv) {
	return felide::App::getInstance()->run(argc, argv);
}
