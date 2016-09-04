
#include "Config.hpp"

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/algorithm.hpp>

namespace felide {
    
    std::vector<felide::view::Filter> Config::getFilters() const {
        std::vector<felide::view::Filter> filters(languages.size());
        
        for (size_t i=0; i<filters.size(); i++) {
            
            felide::view::Filter filter;
            
            filter.desc = languages[i].filterHint;
            filter.extensions = languages[i].extensions;
            
            filters[i] = filter;
        }
        
        return filters;
    }
    
    const Language* Config::findLanguage(const std::string &filepath) const {
        const Language* lang = nullptr;

        namespace fs = boost::filesystem;

        fs::path path(filepath);

        std::wstring filename = path.filename().wstring();
        std::wstring extension = path.extension().wstring();

        // remove dot
        extension.erase(0, 1);    

        // search
        auto langIt = boost::find_if(languages, [extension, filename](const Language &lang){
            auto extIt = boost::find_if(lang.extensions, [extension, filename](const std::string &ext){
                std::wstring wext(ext.begin(), ext.end());

                return wext == extension || wext == filename;
            });

            return extIt != std::end(lang.extensions);
        });

        if (langIt != std::end(languages)) {
            lang = &(*langIt);
        }

        return lang;
    }

    void Config::load(const std::string &file, const LexerConstants &constants) {
        namespace pt = boost::property_tree;

        pt::ptree tree;
        pt::read_json(file, tree);
    
        for (const pt::ptree::value_type &value : tree.get_child("languages")) {
            const auto &langNode = value.second;
            const auto langFile = langNode.get<std::string>("");
        
            auto lang = Language::load(langFile, constants);
        
            languages.push_back(lang);
        }
    }

}
