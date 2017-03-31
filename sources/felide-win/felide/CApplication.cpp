
#include "CApplication.hpp"
#include "CMainFrame.hpp"

namespace felide {
    CApplication::CApplication() {

    }

    CApplication::~CApplication() {}

    int CApplication::run(int argc, char **argv) {
        return 0;
    }
}


#include <atlbase.h>    // base ATL classes
#include <atlapp.h>     // base WTL classes
#include <atlwin.h>     // ATL gui classes
#include <atlframe.h>   // WTL frame window classes
#include <atlmisc.h>    // WTL utility classes like CString
#include <atlcrack.h>   // WTL enhanced msg map macros

class CMainWindow : public CFrameWindowImpl<CMainWindow> {
public:

    DECLARE_FRAME_WND_CLASS(_T("First WTL Window"), IDR_MAINFRAME);

};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    return 0;
}
