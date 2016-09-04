
#include "LexerConstants.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace felide {
    void LexerConstants::load(const std::string &file) {
        namespace pt = boost::property_tree;

        pt::ptree tree;
        pt::read_json(file, tree);

        for (const auto &constantPair : tree.get_child("")) {

            const std::string key = constantPair.first;
            const int value = constantPair.second.get<int>("");

            m_constants[key] = value;
        }
    }

    int LexerConstants::getConstant(const std::string &constantName) const {
        auto found = m_constants.find(constantName);

        if (found != std::end(m_constants)) {
            return found->second;
        } 

        return 0;
    }
}
