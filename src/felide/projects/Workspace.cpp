/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include <felide/projects/Workspace.hpp>

#include <felide/projects/Project.hpp>
#include <map>
#include <list>
#include <algorithm>

namespace felide { namespace projects {
    typedef std::list<Project*> ProjectContainer;

    class Workspace::Private {
    public:
        ProjectContainer projects;
        std::string name;
    };
    
    
    Workspace::Workspace() : impl(nullptr) {
        this->impl.reset(new Workspace::Private());
    }
    
    
    Workspace::Workspace(const std::string &name) : impl(nullptr) {
        this->impl.reset(new Workspace::Private());
        this->setName(name);
    }
    
    
    Workspace::~Workspace() {
        if (this->impl) {
            for (Project *project : this->impl->projects) {
                delete project;
            }
        }
    }
    
    
    std::string Workspace::getName() const {
        assert(this->impl != nullptr);
        
        return this->impl->name;
    }
    
    
    void Workspace::setName(const std::string &name) {
        assert(this->impl != nullptr);
        
        this->impl->name = name;
    }
    
    
    void Workspace::removeProject(Project *project) {
        assert(this->impl != nullptr);
        
        if (project != nullptr) {
            this->impl->projects.remove(project);
            delete project;
        }
    }
    
    
    int Workspace::getProjectCount() const {
        assert(this->impl != nullptr);
        
        return this->impl->projects.size();
    }
    
    
    Project& Workspace::getProject(int index) {
        assert(this->impl != nullptr);
        
        auto position = this->impl->projects.begin();
        std::advance(position, index);
        
        return *(*position);
    }
    
    
    const Project& Workspace::getProject(int index) const {
		assert(this->impl != nullptr);

		auto position = this->impl->projects.begin();
		std::advance(position, index);

		return *(*position);
    }
    
    
    Project& Workspace::getProject(const std::string &projectName) {
        assert(this->impl != nullptr);
        
        auto &projects = this->impl->projects;
        auto position = std::find_if(projects.begin(), projects.end(), [projectName](const Project *project) {
            return project->getName() == projectName;
        });
        
        if (position != projects.end()) {
            return *(*position);
        } else {
            Project *project = new Project();
            project->setName(projectName);
            projects.push_back(project);
            return *project;
        }
    }
    
    /**
     * @brief Get or create a project with the specified name.
     */
    const Project& Workspace::getProject (const std::string &projectName) const {
		assert(this->impl != nullptr);

		auto &projects = this->impl->projects;
		auto position = std::find_if(projects.begin(), projects.end(), [projectName](const Project *project) {
			return project->getName() == projectName;
		});

		if (position != projects.end()) {
			return *(*position);
		}
		else {
			Project *project = new Project();
			project->setName(projectName);
			projects.push_back(project);
			return *project;
		}
    }
}}
