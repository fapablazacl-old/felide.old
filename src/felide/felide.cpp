
#include <map>
#include "felide/App.hpp"
#include "felide/view/gen/Menu.hpp"
#include "felide/view/gen/Generator.hpp"
#include "felide/view/gen/DefaultGenerator.hpp"
#include "felide/view/gen/WindowsGenerator.hpp"

#include <iostream>

#if defined(_WIN32)
#include <Windows.h>
#endif

//class StringResource {
//public:
//    explicit StringResource(std::map<std::string, std::string> strings) 
//        : m_strings(std::move(strings)) {}
//
//    ~StringResource() {}
//
//    std::string get(const std::string &key) const {
//        const auto pos = m_strings.find(key);
//
//        if (pos != m_strings.end()) {
//            return pos->second;
//        } else {
//            return "";
//        }
//    }
//
//private:
//    std::map<std::string, std::string> m_strings;
//};

int main(int argc, char **argv) {

    using namespace felide::view::gen;

    std::map<std::string, std::string> labels_EN = {
        {"file", "&File"}, 
        {"file.new", "&New"}, 
        {"file.open", "&Open ..."}, 
        {"file.save", "&Save"}, 
        {"file.saveall", "Save &All"}, 
        {"file.saveas", "Sa&ve As ..."}, 
        {"file.close", "&Close"}, 
        {"file.exit", "&Exit"}, 
        {"edit", "&Edit"}, 
        {"edit.undo", "&Undo"}, 
        {"edit.redo", "&Redo"}, 
        {"edit.copy", "C&opy"}, 
        {"edit.paste", "&Paste"}, 
        {"view", "&View"},
        {"view.output", "Output Window"},
        {"view.folder", "Folder View"},
        {"help", "&Help"},
        {"help.about", "About"}
    };

    Menu mainMenu = {{
        {"file", {
            {"file.new", {Modifier::Control, Key::N}}, 
            {"-"}, 
            {"file.open", {Modifier::Control, Key::O}}, 
            {"-"}, 
            {"file.save", {Modifier::Control, Key::S}}, 
            {"file.saveall", {Modifier::Control_Shift, Key::S}}, 
            {"file.saveas"}, 
            {"-"}, 
            {"file.close"}, 
            {"-"}, 
            {"file.exit"}, 
        }}, 
        
        {"edit", {
            {"edit.undo"}, 
            {"edit.redo"}, 

            {"edit.cut"}, 
            {"edit.copy"},
            {"edit.paste"}
        }}, 
        
        {"view", {
            {"view.output"},
            {"view.folder"}
        }}, 

        {"help", {
            {"help.about"}
        }}, 
    }};

#if defined(_WIN32)
    WNDCLASS wc = {};

    wc.lpszClassName = "Lala";
    wc.lpfnWndProc = DefWindowProc;
    wc.hbrBackground = (HBRUSH)COLOR_3DFACE;
    wc.hCursor = ::LoadCursor(::GetModuleHandle(NULL), IDC_ARROW);
    wc.hIcon = ::LoadIcon(::GetModuleHandle(NULL), IDC_ICON);
    wc.hInstance = ::GetModuleHandle(NULL);

    ::RegisterClass(&wc);

    HWND hWnd = ::CreateWindow("Lala", "Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);

    WindowsGenerator generator(labels_EN, hWnd);
    generator.generate(mainMenu);

    ShowWindow(hWnd, SW_SHOW);

    MSG msg;

    while (true) {
        if (::PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE) < 0) {
            break;
        } else {
            if (msg.message == WM_QUIT || msg.message == WM_CLOSE) {
                break;
            } else { 
                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
            }
        }
    }

    DestroyWindow(hWnd);

#else 
    Generator generator(labels_EN);
    generator.generate(mainMenu);
#endif

    //try {
    //    return felide::App::getInstance()->run(argc, argv);

    //} catch (const std::exception &exp) {
    //    std::cout << exp.what() << std::endl;
    //}

    return EXIT_SUCCESS;
}
