#pragma once

#ifndef __borc_commandtask_hpp__
#define __borc_commandtask_hpp__

#include "Task.hpp"

#include <string>
#include <vector>

namespace borc {
    class CommandTask : public Task {
    public:
        CommandTask(const std::string &command) : m_command(command) {}

        CommandTask(const std::string &command, const std::vector<std::string> &args) 
            : m_command(command), m_args(args) {}

        virtual void perform() override;

    private:
        std::string m_command;
        std::vector<std::string> m_args;
    };
}

#endif 
