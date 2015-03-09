
#ifndef __FELIDE_MODEL_PROJECT_HPP__
#define __FELIDE_MODEL_PROJECT_HPP__

#include <string>
#include <memory>
#include <felide/model/Source.hpp>
#include <felide/model/ProjectItem.hpp>

namespace felide { namespace model {
	
	class Project {
	public:
		virtual ~Project() = 0;
		
		virtual int getProjectItemCount() const = 0;
		virtual ProjectItem* getProjectItem(int index) = 0;
		virtual const ProjectItem* getProjectItem(int index) const = 0;
		
		virtual void addItem(const ProjectItem &item) = 0;
		virtual void removeItem(const ProjectItem &item) = 0;
		virtual void deleteItem(ProjectItem item) = 0;
	};
	
	typedef std::unique_ptr<Project> ProjectPtr;
}}

#endif	// __FELIDE_MODEL_PROJECT_HPP__
