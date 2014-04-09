/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_PROJECTS_WORKSPACE_HPP__
#define __FELIDE_PROJECTS_WORKSPACE_HPP__

#include <boost/scoped_ptr.hpp>
#include <boost/weak_ptr.hpp>

namespace felide { namespace projects {
    class Project;

    class Workspace {
    public:
        /**
         * @brief Creates a blank workspace with a default name.
         */
        Workspace();
        
        /**
         * @brief Creates a blank workspace with the specified name.
         */
        Workspace(const std::string &name);
        
        ~Workspace();
        
        /**
         * @brief Get the current name of the workspace.
         */
        std::string getName() const;
        
        /**
         * @brief Set the current name of the workspace.
         */
        void setName(const std::string &name);
        
        /**
         * @brief Add a new project to the workspace.
         */
        Project& addProject(const std::string &projectName);
        
        /**
         * @brief Remove a project from the workspace.
         */
        void removeProject(Project *project);
        
        /**
         * @brief Get the current project count of the workspace.
         */
        int getProjectCount() const;
        
        /**
         * @brief Get the project located at the specified index.
         */
        Project& getProject(int index);
        
        /**
         * @brief Get the project located at the specifid index.
         */
        const Project& getProject(int index) const;
        
        /**
         * @brief Get or create a project with the specified name.
         */
        Project& getProject (const std::string &projectName);
        
        /**
         * @brief Get or create a project with the specified name.
         */
        const Project& getProject (const std::string &projectName) const;
        
    private:
        class Private;
        boost::scoped_ptr<Private> impl;
    };
}}

#endif	//__FELIDE_PROJECTS_WORKSPACE_HPP__
