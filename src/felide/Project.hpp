
#ifndef __FELIDE_MODEL_PROJECT_HPP__
#define __FELIDE_MODEL_PROJECT_HPP__

#include <string>
#include <memory>
#include "ProjectItem.hpp"

namespace felide { 
	class Project {
	public:
		virtual ~Project() = 0;
		
		virtual int getItemCount() const = 0;
		virtual ProjectItem* getItem(int index) = 0;
		virtual const ProjectItem* getItem(int index) const = 0;
		
		virtual void addItem(const ProjectItem &item) = 0;
		virtual void removeItem(const ProjectItem &item) = 0;
		virtual void deleteItem(ProjectItem item) = 0;
	};
	
	typedef std::unique_ptr<Project> ProjectPtr;
}

#endif	// __FELIDE_MODEL_PROJECT_HPP__
