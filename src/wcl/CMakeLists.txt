
SET (wcl_src
    wcl.hpp 
    AcceleratorTable.hpp 
    Application.hpp 
    Bitmap.hpp 
    Button.hpp 
    COMApplication.hpp 
    COMException.hpp 
    COMResult.hpp 
    Dialog.hpp 
    Edit.hpp 
    Exception.hpp 
    Frame.hpp 
    ImageList.hpp
    Menu.hpp 
    Module.hpp 
    Rect.hpp 
    Scintilla.cpp 
    Scintilla.hpp 
    Sizer.hpp 
    Static.hpp 
    TabControl.hpp 
    TreeView.hpp
    Window.hpp 
    WindowBase.hpp 
    WindowClass.hpp 
    WindowHandle.hpp 
)

SET (wcl_gen_src
    gen/Menu.hpp 
)

SET (wcl_ex_src
    ex/TabbedPanel.hpp 
)

SET (wcl_util_src
    util/String.hpp 
)

SET (wcl_xml_src
    xml/Document.hpp 
    xml/Node.hpp 
)

SOURCE_GROUP(wcl         FILES ${wcl_src})
SOURCE_GROUP(wcl/gen     FILES ${wcl_gen_src})
SOURCE_GROUP(wcl/ex     FILES ${wcl_ex_src})
SOURCE_GROUP(wcl/util     FILES ${wcl_util_src})
SOURCE_GROUP(wcl/xml     FILES ${wcl_xml_src})

ADD_LIBRARY (wcl 
    ${wcl_src}
    ${wcl_gen_src}
    ${wcl_ex_src}
    ${wcl_util_src}
    ${wcl_xml_src}
)
