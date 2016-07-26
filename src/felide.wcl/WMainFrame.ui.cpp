
#include "WMainFrame.hpp"

#include <map>
#include <wcl/gen/Menu.hpp>
#include <wcl/Bitmap.hpp>
#include <wcl/Edit.hpp>

namespace felide { namespace view { namespace win {

    void WMainFrame::OnCreate() {
        std::vector<wcl::Accelerator> accelerators = {
            {ID_FILE_NEW,        FVIRTKEY | FCONTROL,            'N'},
            {ID_FILE_OPEN,        FVIRTKEY | FCONTROL,            'O'},
            {ID_FILE_SAVE,        FVIRTKEY | FCONTROL,            'S'},
            {ID_FILE_SAVEAS ,    FVIRTKEY | FCONTROL | FALT,        'S'},
            {ID_FILE_SAVEALL,    FVIRTKEY | FCONTROL | FSHIFT,    'S'},
            {ID_FILE_PRINT,        FVIRTKEY | FCONTROL,            'P'},
            {ID_FILE_EXIT,        FVIRTKEY | FALT,    VK_F4}
        };

        wcl::gen::Menu MainFrameMenu = {{
            {
                L"&File" , { 
                {ID_FILE_NEW        , L"&New ..."},
                {0, L"-"},
                {ID_FILE_OPEN        , L"&Open ..."},
                {0, L"-"},
                {ID_FILE_SAVE        , L"&Save"},
                {ID_FILE_SAVEAS        , L"Save &As ..."},
                {ID_FILE_SAVEALL    , L"Save A&ll"},
                {0, L"-"},
                {ID_FILE_PRINT        , L"&Print ..."},
                {0, L"-"},
                {ID_FILE_CLOSE        , L"&Close"},
                {ID_FILE_CLOSEALL    , L"Cl&ose All"},
                {0, L"-"},
                {ID_FILE_EXIT        , L"&Exit"}}
            },

            {
                L"&Edit" , { 
                {ID_EDIT_UNDO        , L"&Undo"},
                {ID_EDIT_REDO        , L"&Redo"},
                {0, L"-"},
                {ID_EDIT_CUT        , L"&Cut"},
                {ID_EDIT_COPY        , L"C&opy"},
                {ID_EDIT_PASTE        , L"&Paste"},
                {0, L"-"},
                {ID_EDIT_SEARCH        , L"&Search"},
                {ID_EDIT_REPLACE    , L"&Replace"}}
            },
    
            {
                L"&View" , { 
                {ID_VIEW_PROJECT    , L"&Project"},
                {ID_VIEW_CLASSVIEW    , L"&Classes"},
                {ID_VIEW_OUTPUT        , L"&Output Window"},
                {ID_VIEW_LOG        , L"IDE &Log"}}
            },
    
            {
                L"&Project" , { 
                {ID_PROJECT_MAKE        , L"&Make"},
                {ID_PROJECT_INSTALL    , L"&Install"},
                {0, L"-"},
                {ID_PROJECT_CLEAN        , L"&Clean"},
                {0, L"-"},
                {ID_PROJECT_PROPERTIES, L"&Properties"}}
            },
    
            {
                L"&Debug" , { 
                {ID_DEBUG_START                    , L"&Start"},
                {ID_DEBUG_RESUME                , L"&Pause"},
                {ID_DEBUG_PAUSE                    , L"&Resume"},
                {0, L"-"},
                {ID_DEBUG_STOP                    , L"S&top"},
                {0, L"-"},
                {ID_DEBUG_STARTWITHOUTDEBUGGING    , L"Start &without Debugging"}, 
                {0, L"-"},
                {ID_DEBUG_BREAKPOINTADD            , L"&Add Breakpoint"}, 
                {ID_DEBUG_BREAKPOINTREMOVE        , L"R&emove Breakpoint"}}
            },
    
            {
                L"&Tools" , {{ID_TOOLS_OPTIONS, L"&Options ..."}}
            },
    
            {
                L"&Help" , {{ID_HELP_ABOUT, L"&About ..."}}
            }
        }};

        auto menu = MainFrameMenu.Generate(accelerators);
    
        ::SetMenu(this->GetHandle(), menu->GetHandle());

        m_menu = std::move(menu);

        m_acceleratorTable = std::make_unique<wcl::AcceleratorTable>();
        m_acceleratorTable->Create(accelerators.data(), accelerators.size());

        //m_imageList = std::make_unique<wcl::ImageList>();
        //m_imageList->Create(16, 16, ILC_COLOR24|ILC_MASK, 10, 4);
        //m_imageList->AddMasked(wcl::Bitmap::Load(L"assets\\Interface_8336_24.bmp")->GetHandle(), RGB(255, 0, 255));
        //m_imageList->AddMasked(wcl::Bitmap::Load(L"assets\\Link_5762_24.bmp")->GetHandle(), RGB(255, 0, 255));

        //const int TREEVIEW_STYLE = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT ;

        //m_treeView = std::make_unique<wcl::TreeView>();
        //m_treeView->Create(L"", TREEVIEW_STYLE, 0, 0, 300, 300, this->GetHandle());
        //
        //// Associate the image list with the tree-view control. 
        //m_treeView->SetImageList(TVSIL_NORMAL, m_imageList.get());

        //gen::TreeViewItem treeViewData = {
        //    0, 0, L"wcl", {
        //        { 1, 1, L"libwcl"},
        //        { 1, 1, L"wclrc"},
        //        { 1, 1, L"test01"}
        //    }
        //};
        //
        //treeViewData.Generate(m_treeView.get(), TVI_ROOT);

        // m_sizer.Add(m_treeView.get(), wcl::SizerStyle::Expand);

        //m_textEditor.Create(L"", WS_CHILD | WS_VISIBLE, 0, 0, 10, 10, this->GetHandle());
        //m_textEditor.SetStyle(STYLE_DEFAULT, wcl::ScintillaColors::Black, wcl::ScintillaColors::White, 8, "Courier");
        //m_textEditor.SetTabWidth(4);

        m_tabbedPanel.CreateEx(WS_EX_CLIENTEDGE, L"", WS_CHILD | WS_VISIBLE | SS_SIMPLE, 10, 10, 300, 300, this->GetHandle());

        auto sci1 = std::make_unique<wcl::Scintilla>();
        sci1->CreateEx(WS_EX_CLIENTEDGE, L"Test Text", WS_CHILD, 10, 10, 50, 50, this->GetHandle());

        //auto sci2 = std::make_unique<wcl::Scintilla>();
        //sci2->CreateEx(WS_EX_CLIENTEDGE, L"Test Text 2", WS_CHILD, 10, 10, 50, 50, this->GetHandle());

        // m_tabbedPanel.Insert(L"Test!", std::move(sci1));
        // m_tabbedPanel.Insert(L"Test!", std::move(sci2));

        m_sizer.Add(&m_tabbedPanel, wcl::SizerStyle::Expand);
    }
}}}
