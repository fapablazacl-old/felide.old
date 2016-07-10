
#ifndef __felide_lexer_hpp__
#define __felide_lexer_hpp__

#include <cstdint>
#include <vector>
#include <map>

namespace felide {

    struct Color {
        uint8_t r=0, g=0, b=0, a=255;
        Color(uint8_t r_=0, uint8_t g_=0, uint8_t b_=0, uint8_t a_=255) : r(r_), g(g_), b(b_), a(a_) {}
    };

    /**
    * @brief Information needed by the lexer for syntax coloring
    */
    struct Lexer {
        //! The ID of the scintilla lexer.
        int name = 0;

        //! A list of keywords 
        std::vector<std::string> keywords;

        //! Token - Color map.
        std::map<int, Color> colors;
    };
}

#endif
