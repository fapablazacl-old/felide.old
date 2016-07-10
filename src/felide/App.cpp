
#include "App.hpp"

namespace felide {
    App::App() {
        m_constants.load("scintilla.json");
        m_config.load("ide.json", m_constants);
    }
}
