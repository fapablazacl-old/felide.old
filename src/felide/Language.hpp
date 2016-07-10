
#ifndef __felide_language_hpp__
#define __felide_language_hpp__

#include "felide/Lexer.hpp"
#include "felide/LexerConstants.hpp"

namespace felide {
    
    /**
     * @brief Programming Language configuration. Holds all the information needed by the IDE to "know" the language.
     */
    struct Language {
        //! The language name
        std::string name;	

        //! The hint shown in the file open/save dialog to describe the filter.	
        std::string filterHint;	

        //! A list of extensions, without dots, handled by the language.
        std::vector<std::string> extensions;	

        //! Information needed by the lexer for syntax coloring
        Lexer lexer;	

        /**
        * @brief Load the language configuration from the specified JSON file.
        */
        static Language load(const std::string &file, const LexerConstants &constants);
    };
}

#endif
