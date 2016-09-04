
#include "FelideApp.hpp"

namespace felide {

    static std::map<std::string, std::string> labels_EN = {
        {"file", "&File"}, 
        {"file.new", "&New"}, 
        {"file.open", "&Open ..."}, 
        {"file.save", "&Save"}, 
        {"file.saveall", "Save &All"}, 
        {"file.saveas", "Sa&ve As ..."}, 
        {"file.close", "&Close"}, 
        {"file.exit", "&Exit"}, 
        {"edit", "&Edit"}, 
        {"edit.cut", "&Cut"}, 
        {"edit.undo", "&Undo"}, 
        {"edit.redo", "&Redo"}, 
        {"edit.copy", "C&opy"}, 
        {"edit.paste", "&Paste"}, 
        {"view", "&View"},
        {"view.output", "&Output Window"},
        {"view.folder", "&Folder View"},
        {"help", "&Help"},
        {"help.about", "&About"}
    };

    static Menu mainMenu = {{
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

    FelideApp::FelideApp() {
        m_labels_EN = labels_EN;
        m_mainMenu = mainMenu;

        this->getPluginManager()->load("felide.windows");
    }

    FelideApp::~FelideApp() {
        this->getPluginManager()->unload("felide.windows");
    }

    int FelideApp::run() {
        m_mainFrame = this->getViewFactory()->createMainFrame(&m_labels_EN);
        m_mainFrame->setHandler(&m_mainHandler);
        m_mainFrame->setMenu(m_mainMenu);

        return this->getViewFactory()->mainLoop();
    }
}
