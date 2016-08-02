
#include "Builder.hpp"

#include <iostream>

namespace felide { namespace pom {
    void Builder::execute(const std::vector<std::string> &commands) {
        for (const std::string &command : commands) {

#if defined(_DEBUG)
            std::cout << command << std::endl;
#endif

            const int result = std::system(command.c_str());

            if (result) {
                auto msg = std::string() 
                    + "The command exited with code " 
                    + "'" + std::to_string(result) + "'";

                throw std::runtime_error(msg);
            }
        }
    }
}}
