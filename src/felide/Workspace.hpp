/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_WORKSPACE_HPP__
#define __FELIDE_WORKSPACE_HPP__

#include <memory>
#include <string>

#include "Config.hpp"
#include "Project.hpp"

namespace felide { 

	class FELIDE_API Workspace {
	public:
		virtual ~Workspace() = 0;
		
		virtual int getProjectCount() const = 0;
		virtual Project* getProject(int i) = 0;
		virtual const Project* getProject(int i) const = 0;
		
		virtual void addProject(ProjectPtr project) = 0;
		virtual void removeProject(ProjectPtr project) = 0;
		virtual void deleteProject(ProjectPtr project) = 0;
		
		virtual std::string getName() const = 0;
		virtual void setName(const std::string &name) = 0;
	};
	
	typedef std::unique_ptr<Workspace> WorkspacePtr;
}

#endif	// __FELIDE_WORKSPACE_HPP__
