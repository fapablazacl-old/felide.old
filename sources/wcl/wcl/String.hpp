
#pragma once

#ifndef __wcl_string_hpp__
#define __wcl_string_hpp__

#include <string>

namespace wcl {
#if defined(_UNICODE)
    typedef std::wstring string;
#else 
    typedef std::string string;
#endif

    inline string str(const std::wstring src) {
        return string(src.begin(), src.end());
    }

    inline string str(const std::string src) {
        return string(src.begin(), src.end());
    }
}

#endif 
