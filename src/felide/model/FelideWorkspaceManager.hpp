
#ifndef __FELIDE_MODEL_FELIDEWORKSPACEMANAGER_HPP__
#define __FELIDE_MODEL_FELIDEWORKSPACEMANAGER_HPP__

#include <memory>
#include <felide/model/WorkspaceManager.hpp>

namespace felide { namespace model { 
	
	class FelideWorkspaceManager : public WorkspaceManager {
	public:
		FelideWorkspaceManager();
		~FelideWorkspaceManager();
		
		virtual WorkspacePtr createWorkspace(const std::string &path) override;
		
	private:
		struct Impl;
		std::unique_ptr<Impl> impl;
	};
	
}}

#endif	// __FELIDE_MODEL_FELIDEWORKSPACEMANAGER_HPP__
