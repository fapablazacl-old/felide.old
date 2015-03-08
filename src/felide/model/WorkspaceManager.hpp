
#ifndef __FELIDE_MODEL_WORKSPACEMANAGER_HPP__
#define __FELIDE_MODEL_WORKSPACEMANAGER_HPP__

#include <string>

#include <felide/model/Project.hpp>
#include <felide/model/Workspace.hpp>

namespace felide { namespace model {	
	/**
	 * @brief Manages the creation of workspaces.
	 * 
	 * 	A WorkspaceManager handles the creation of different types of workspaces.
	 */
	class WorkspaceManager {
	public:
		virtual ~WorkspaceManager();
		
		/**
		 * @brief Create a empty content Workspace files and directory structure on the specified path.
		 */
		virtual WorkspacePtr createWorkspace(const std::string &path) = 0;
	}
}}

#endif	// __FELIDE_MODEL_WORKSPACEMANAGER_HPP__
