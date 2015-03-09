
#include "FelideWorkspaceManager.hpp"

#include <list>
#include <memory>

namespace felide { namespace model { 
	
	class FelideProject : public Project {
	public:
		~FelideProject() {}
		
		int getProjectItemCount() const  {
			return 0;
		}
		
		ProjectItem* getProjectItem(int index)  {
			return nullptr;
		}
		
		const ProjectItem* getProjectItem(int index) const  {
			return nullptr;
		}
		
		void addItem(const ProjectItem &item)  {
		}
		
		void removeItem(const ProjectItem &item)  {
		}
		
		void deleteItem(ProjectItem item)  {
		}
		
	private:
		std::list<ProjectItem> items;
	};
	
	class FelideWorkspace : public Workspace {
	public:
		virtual ~FelideWorkspace() 
		{
		}
	
	
	};
	
	WorkspacePtr FelideWorkspaceManager::createWorkspace(const std::string &path)
	{
		return WorkspacePtr();
	}
}}
