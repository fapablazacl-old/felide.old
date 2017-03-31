#pragma once

#ifndef __borc_mkdirtask_hpp__
#define __borc_mkdirtask_hpp__

#include "Task.hpp"
#include <string>

namespace borc {
    class DirectoryTask : public Task {
    public:
        DirectoryTask(const std::string &directory);

        virtual void perform() override;

    private:
        std::string m_directory;
    };
}

#endif
