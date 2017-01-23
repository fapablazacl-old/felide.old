
#pragma once

#ifndef __borc_version_hpp__
#define __borc_version_hpp__

#if defined(major)
#undef major
#endif

#if defined(minor)
#undef minor
#endif

namespace borc {
    struct Version {
        int major = 0;
        int minor = 0;
        int build = 0;
    
        Version() {}
    
        Version(int major_, int minor_, int build_=0)
            : major(major_), minor(minor_), build(build_) {}
    };
    
    extern bool operator< (const Version &v1, const Version &v2);
    
    extern bool operator== (const Version &v1, const Version &v2);
    
    inline bool operator!= (const Version &v1, const Version &v2) {
        return !(v1 == v2);
    }
}

#endif
