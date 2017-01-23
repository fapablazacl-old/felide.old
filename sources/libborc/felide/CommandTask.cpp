
#include "CommandTask.hpp"

#include <cstdlib>
#include <iostream>
#include <boost/algorithm/string/join.hpp>

namespace borc {
    void CommandTask::perform() {
        std::string cmd = m_command + " " +  boost::join(m_args, " ");
    
        
        std::cout << cmd << std::endl;
        
        int exitCode = std::system(cmd.c_str());

        if (exitCode != 0) {
            throw std::runtime_error("Build task failed: ");
        }
    }
}
