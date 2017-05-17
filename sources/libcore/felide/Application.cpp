
#include "Application.hpp"

#include "Plugin.hpp"
#include "PluginManager.hpp"

#include "Resource.hpp"
#include "ResourceManagerImpl.hpp"
#include "Menu.hpp"

#include <cassert>
#include <vector>
#include <memory>

namespace felide {

    class PluginImpl : public Plugin {
    public:
        PluginImpl(const std::string &name)
            : m_name(name) {}

        virtual std::string getName() const override {
            return m_name;
        }

    private:
        std::string m_name;
    };

    class PluginManagerImpl : public PluginManager {
    public:
        PluginManagerImpl() {
            m_plugins.emplace_back(new PluginImpl("C++"));
            m_plugins.emplace_back(new PluginImpl("GLSL"));
        }

        virtual std::size_t getPluginCount() const override {
            return (int)m_plugins.size();
        }

        virtual Plugin* getPlugin(const std::size_t index) const override {
            return m_plugins[index].get();
        }

    private:
        std::vector<std::unique_ptr<Plugin>> m_plugins;
    };

    struct Application::Private {
        PluginManagerImpl m_pluginManager;
        ResourceManagerImpl m_resourceManager;
    };

    Application::Application() {
        m_impl = new Application::Private();

        auto stringResource = std::make_unique<StringResource>("strings");

        // Populate application strings
        std::map<std::string, std::string> strings = {
            {"file", "&File"},
            {"file.openfolder", "&Open Folder"},
            {"file.save", "&Save"},
            {"file.saveall", "Save &All"},
            {"file.exit", "&Exit"},
            {"edit", "&Edit"},
            {"edit.undo", "&Undo"},
            {"edit.redo", "&Redo"},
            {"edit.cut", "&Cut"},
            {"edit.copy", "&Copy"},
            {"edit.paste", "&Paste"},
            {"help", "&Help"},
            {"help.about", "&About"}
        };

        for (const auto &pair : strings) {
            stringResource->set(pair.first, pair.second);
        }

        m_impl->m_resourceManager.addResource(std::move(stringResource));

        // Populate main menu structure
        MenuBar menuBar {
            Menu("file", {
                Menu::item("file.openfolder"),
                Menu::separator(),
                Menu::item("file.save"),
                Menu::item("file.saveall"),
                Menu::separator(),
                Menu::item("file.exit")
            }),

            Menu("edit", {
                Menu::item("edit.undo"),
                Menu::item("edit.redo"),
                Menu::separator(),
                Menu::item("edit.cut"),
                Menu::item("edit.copy"),
                Menu::item("edit.paste")
            }),

            Menu("help", {
                Menu::item("help.about")
            })
        };

        auto menuBarResource = std::make_unique<ResourceWrapper<MenuBar>>("menuBar", menuBar);
        m_impl->m_resourceManager.addResource(std::move(menuBarResource));
    }

    Application::~Application() {
        delete m_impl;
    }

    PluginManager* Application::getPluginManager() {
        assert(m_impl);

        return &m_impl->m_pluginManager;
    }

    const ResourceManager* Application::getResourceManager() {
        assert(m_impl);

        return &m_impl->m_resourceManager;
    }
}
