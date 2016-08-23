
#include "Locator.hpp"

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace felide {  namespace core {
    std::string Locator::locate(const std::string &name) {
        namespace fs = boost::filesystem;

        std::string location = name;

        for (const std::string &path : m_paths) {
            location = path + name;

            if (fs::exists(fs::path(location))) {
                break;
            }
        }

        return location;
    }
}}
