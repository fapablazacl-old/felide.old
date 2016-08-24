
#pragma once

#ifndef __felide_core_fileutil_hpp__
#define __felide_core_fileutil_hpp__

#include <string>

namespace felide {  namespace core {

    class FileUtil {
        FileUtil() = delete;
        FileUtil(const FileUtil &) = delete;

    public:
        static std::string load(const std::string &file);

        static void save(const std::string &file, const std::string &content);
    };

}}

#endif
