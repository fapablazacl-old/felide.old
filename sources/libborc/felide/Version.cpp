
#include "Version.hpp"

namespace borc {
    bool operator== (const Version &v1, const Version &v2) {
        if (v1.major!=v2.major) {
            return false;
        }
        
        if (v1.minor!=v2.minor) {
            return false;
        }
        
        if (v1.build!=v2.build) {
            return false;
        }
        
        return true;
    }
    
    bool operator< (const Version &v1, const Version &v2) {
        if (v1.major>=v2.major) {
            return false;
        }
        
        if (v1.minor>=v2.minor) {
            return false;
        }
        
        if (v1.build>=v2.build) {
            return false;
        }
        
        return true;
    }
}
