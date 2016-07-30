
#include "Language.hpp"

#include "Item.hpp"
#include <boost/filesystem/path.hpp>

namespace felide { namespace pom {
    bool Language::isItemCompilable(const Item *item) const {
        const boost::filesystem::path fspath(item->path);
        const std::string ext = fspath.extension().string();

        return ext == ".cpp";
    }    
}}
