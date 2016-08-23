/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "Workspace.hpp"

#include "felide/system/Process.hpp"
#include <boost/format.hpp>

namespace felide { 
    std::string Workspace::execute(const std::list<std::string> &commands) {
        
        std::string result;
        
        for (const auto &command : commands) {
        //    auto process = felide::system::Process::open(felide::system::ProcessFlags::Redirect, command);
        //    
        //    process->start();
        //    process->wait();
        //    
        //    result += process->getOutput();
        //    
        //    // int result = std::system(command.c_str());
        //    // 
        //    // if (result != 0) {
        //    //     boost::format format("The command '%s' exited with the error code %n");
        //    //     throw std::runtime_error(boost::str(format % command % result));
        //    // }
        }
        
        return result;
    }
}
