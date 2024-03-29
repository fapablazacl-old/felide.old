
#pragma once

#include <string>
#include <map>
#include <vector>

#include "felide_old/Config.hpp"
#include "felide_old/Lexer.hpp"
#include "felide_old/LexerConstants.hpp"
#include "felide_old/Language.hpp"
#include "felide_old/view/DialogFactory.hpp"

namespace felide {

    class App {
    public:
        App();
        virtual ~App() {}

        virtual int run(int argc, char **argv) = 0;

        Config* getConfig() {
            return &m_config;
        }

        const Config* getConfig() const {
            return &m_config;
        }

        std::string getTitle() const {
            return "felide";
        }

        virtual felide::view::DialogFactory* getDialogFactory() = 0;
        
        virtual const felide::view::DialogFactory* getDialogFactory() const = 0;
        
    public:
        // implemented in the toolkit-specific implementation...
        static App* getInstance();

    private:
        Config m_config;
        LexerConstants m_constants;
    };
}
