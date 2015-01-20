
#ifndef __FELIDE_MODEL_UTIL_UTIL_HPP__
#define __FELIDE_MODEL_UTIL_UTIL_HPP__

#include <string>

namespace felide { namespace model { namespace util {
    int hash(const std::string &str);
    
    std::string getTempPath();
}}}

#endif // __FELIDE_MODEL_UTIL_UTIL_HPP__
