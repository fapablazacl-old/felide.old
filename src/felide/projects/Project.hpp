/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_PROJECTS_PROJECT_HPP__
#define __FELIDE_PROJECTS_PROJECT_HPP__

#include <boost/scoped_ptr.hpp>
#include <felide/projects/ProjectItem.hpp>

namespace felide { namespace projects {
	/**
	 * @brief A collection of files, many of them used in the process of building a software solution.
	 */
	class Project {
	public:
		Project();
		~Project();
        
        /**
         * @brief Set the name of the current Project.
         *
         * The name must only consist of alphanumeric characters, starting with a alphanumeric one, 
         * and must not be an empty string.
         * Failure to the condition above, this method raises a std::runtime_error exception.
         */
        void setName(const std::string &name);
        
        /**
         * @brief Get the name of the project.
         */
        std::string getName() const;
        
        /**
         * @brief Add the specified item to the current project.
         * 
         * If the specified object already exist, this method does nothing.
         * If the specified object is null, this method raises a std::runtime_error exception.
         */        
        void addProjectItem(ProjectItem *projectItem);
        
        /**
         * @brief Remove (doesn't delete) the specified item from the current project.
         *
         * If the specified item doesn't exists, this method does nothing.
         * If the specified item is null, this method raises a std::runtime_error exception.
         */
        void removeProjectItem(ProjectItem *projectItem);
        
        /**
         * @brief Return the current item count of the current project.
         */
        int getProjectItemCount() const;

        /**
         * @brief Get the item located in the specified index.
         *
         * If the index is negative, or greater or equal to the count of items of the project, 
         * this method raises a std::runtime_error exception.
         *
         * The returned object is guaranteed to be a non-null object.
         */
        ProjectItem* getProjectItem(int index);
        
        /**
         * @brief Get the constant item located in the specified index.
         *
         * If the index is negative, or greater or equal to the count of items of the project, 
         * this method raises a std::runtime_error exception.
         *
         * The returned object is guaranteed to be a non-null object.
         */
        const ProjectItem* getProjectItem(int index) const;
        
	private:
		class Private;
		boost::scoped_ptr<Private> impl;
	};
}}

#endif	//__FELIDE_PROJECT_HPP__
