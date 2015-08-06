
#ifndef __felide_toolchain_hpp__
#define __felide_toolchain_hpp__

#include "Workspace.hpp"
#include "Project.hpp"
#include "ProjectItem.hpp"

namespace felide {
	class Toolchain {
	public:
		/**
		 * @brief Build a single item
		 */
		void build(ProjectItem *item);
	};
}

#endif	// __felide_toolchain_hpp__
