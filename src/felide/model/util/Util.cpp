
#include "Util.hpp"

#include <boost/functional/hash.hpp>
#include <boost/lexical_cast.hpp>

namespace felide { namespace model { namespace util {
    
    int hash(const std::string &str)
    {
        boost::hash<std::string> hash;
        return hash(str);
    }
    
    std::string getTempPath() 
    {
        return "/var/tmp/";
    } 
}}}
