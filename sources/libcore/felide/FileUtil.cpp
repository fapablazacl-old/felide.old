
#include "FileUtil.hpp"

#include <fstream>
#include <cassert>

namespace felide {

    std::string FileUtil::loadFile(const std::string &path) {
        std::string line;
        std::string content;
        std::fstream fs;

        fs.open(path.c_str(), std::ios::in);

        assert(fs.is_open());

        while (!fs.eof()) {
            std::getline(fs, line);
            content += (line + "\n");
        }

        return content;
    }

    void FileUtil::saveFile(const std::string &path, const std::string &content) {
        assert(false);
    }
}
