
#pragma once 

#ifndef __felide_fileutil_hpp__
#define __felide_fileutil_hpp__

#include <string>

namespace felide {

    class FileUtil {
    public:
        static std::string loadFile(const std::string &path);

        static void saveFile(const std::string &path, const std::string &content);

    private:
        FileUtil() = delete;
    };
}

#endif
