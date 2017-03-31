
#pragma once

#ifndef __borc_toolchain_hpp__
#define __borc_toolchain_hpp__

#include "Version.hpp"
#include "Project.hpp"
#include "Task.hpp"

#include <memory>

namespace borc {
    struct ToolChainInfo {
        std::string name;
        std::string provider;

        Arch targetArch = Arch::Unknown;

        Version version;

        ToolChainInfo() {}

        ToolChainInfo(std::string name_, std::string provider_, Version version_) 
            : name(name_), provider(provider_), version(version_) {}
    };

    class ToolChain {
    public:
        virtual ~ToolChain();

        virtual ToolChainInfo getInfo() const = 0;

        virtual std::vector<std::unique_ptr<Task>> generateBuildTasks(const Project &project) = 0;
    };
}

#endif 
