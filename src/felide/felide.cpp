
#include "felide/App.hpp"

#include <iostream>

int main(int argc, char **argv) {

    try {
        return felide::App::getInstance()->run(argc, argv);

    } catch (const std::exception &exp) {
        std::cout << exp.what() << std::endl;
    }
}
