
#ifndef __felide_config_hpp__
#define __felide_config_hpp__

#include <vector>
#include "felide/Language.hpp"
#include "felide/view/DialogFactory.hpp"

namespace felide {
    
    /**
     * IDE - wide configuration settings
     */
    struct Config {
        std::vector<Language> languages;
        
        std::vector<felide::view::Filter> getFilters() const;
        
        /**
        * @brief Get the Language description data from the specified file path.
        */
        const Language* findLanguage(const std::string &filepath) const;

        void load(const std::string &file, const LexerConstants &constants);
    };
}

#endif
