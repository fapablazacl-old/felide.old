
#pragma once

#ifndef __felide_project_hpp__
#define __felide_project_hpp__

#include <vector>
#include <memory>

namespace felide {
    class Target;
    class Project {
    public:
        virtual ~Project();

        virtual std::vector<Target*> getTargets() const = 0;

        virtual void addTarget(std::unique_ptr<Target> target) = 0;

        virtual std::unique_ptr<Target> removeTarget(Target *target) = 0;
    };
}

#endif
