
#include "DefaultGenerator.hpp"

#include <iostream>

namespace felide { namespace view { namespace gen {

    DefaultGenerator::DefaultGenerator(const std::map<std::string, std::string> &labels) 
        : m_labels(labels) {}

    DefaultGenerator::~DefaultGenerator() {}

    void DefaultGenerator::generate(const Menu &menu) {
        this->generateImpl(menu, 0);
    }

    void DefaultGenerator::generateImpl(const Menu &menu, const int level) {
        std::cout << std::string(level, '-') << m_labels[menu.key] << std::endl;

        for (const Menu &child : menu.childs) {
            this->generateImpl(child, level + 2);
        }
    }
}}}
