
#ifndef __FELIDE_MODEL_WORKSPACE_HPP__
#define __FELIDE_MODEL_WORKSPACE_HPP__

#include <memory>
#include <string>

#include <felide/model/Project.hpp>

namespace felide { namespace model {

	class Workspace {
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
}}

#endif	// __FELIDE_MODEL_WORKSPACE_HPP__
