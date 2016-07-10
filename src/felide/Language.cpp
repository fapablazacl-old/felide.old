
#include "Language.hpp"

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/algorithm.hpp>

namespace felide {
    
    Language Language::load(const std::string &file, const LexerConstants &constants) {
	namespace pt = boost::property_tree;

	pt::ptree tree;
	pt::read_json(file, tree);
		
	Language lang;
	
	// extract desc
	lang.name = tree.get<std::string>("name");
	lang.filterHint = tree.get<std::string>("filter");
	
	// extract extensions
	std::string exts = tree.get<std::string>("extensions");
	boost::split(lang.extensions, exts, boost::is_any_of(","));

	// trim spaces from extensions
	for (auto &ext : lang.extensions) {
            boost::trim(ext);
	}

	// extract lexer name
	lang.lexer.name = constants.getConstant(tree.get<std::string>("lexer.name"));
		
	// extract keywords
	for (const auto &keywordsPair : tree.get_child("lexer.keywords")) {
	    const auto &keywordsNode = keywordsPair.second;

	    std::string keywords = keywordsNode.get<std::string>("");

	    std::vector<std::string> keywordArray;

	    boost::split(keywordArray, keywords, boost::is_any_of(","));

	    lang.lexer.keywords.insert(lang.lexer.keywords.end(), keywordArray.begin(), keywordArray.end());
	}

	// trim spaces from extensions
	for (auto &keyword : lang.lexer.keywords) {
	    boost::trim(keyword);
	}

	// extract color information
	for (const auto pair : tree.get_child("lexer.colors")) {
	    // parse the color triplet
	    const std::string rgb = pair.second.get<std::string>("");

	    std::vector<std::string> color;
	    boost::split(color, rgb, boost::is_any_of(","));

	    std::vector<int> colori(color.size());

	    std::transform(std::begin(color), std::end(color), std::begin(colori), [](const std::string &component) {
                return boost::lexical_cast<int>(boost::trim_copy(component));
	    });

	    // add the lexer token - color map
	    const int key = constants.getConstant(pair.first);
	    const Color value = Color(colori[0], colori[1], colori[2]);

	    lang.lexer.colors[key] = value;
	}
	
	return lang;
    }
}
