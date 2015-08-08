/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

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
