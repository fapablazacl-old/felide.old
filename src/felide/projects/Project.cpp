/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include <list>
#include <algorithm>
#include <stdexcept>
#include <felide/projects/Project.hpp>

namespace felide { namespace projects {
    typedef std::list<ProjectItem *> ProjectItemCollection;
    typedef ProjectItemCollection::iterator ProjectItemCollectionIt;

    class Project::Private {
    public:
        ProjectItemCollection projectItems;
        std::string name;
    };
    
    
    Project::Project() : impl(new Project::Private()) {
    }
    
    Project::~Project() {
    }
    
    
    void Project::addProjectItem(ProjectItem *projectItem) {
        assert(this->impl != nullptr);
        
        this->impl->projectItems.push_back(projectItem);
        this->impl->projectItems.unique();
    }

    void Project::removeProjectItem(ProjectItem *projectItem) {
        assert(this->impl != nullptr);
        
        this->impl->projectItems.remove(projectItem);
    }
    
    int Project::getProjectItemCount() const {
        assert(this->impl != nullptr);
        
        return this->impl->projectItems.size();
    }
    
    ProjectItem* Project::getProjectItem(int index) {
        assert(this->impl != nullptr);
        
        if (index >=  this->getProjectItemCount()) {            
            throw std::runtime_error("felide::projects::Project::getProjectItem: The supplied index ");
        }
        
        auto projectItemIt = this->impl->projectItems.begin();
        std::advance(projectItemIt, index);
        
        return *projectItemIt;
    }
    
    const ProjectItem* Project::getProjectItem(int index) const {
        assert(this->impl != nullptr);
        const Project *project = this;
        return project->getProjectItem(index);
    }
    
    void Project::setName(const std::string &name) {
        assert(this->impl != nullptr);
        this->impl->name = name;
    }

    std::string Project::getName() const {
        assert(this->impl != nullptr);
        return this->impl->name;
    }
}}
