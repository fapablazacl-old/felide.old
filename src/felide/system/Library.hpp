/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_SYSTEM_LIBRARY_HPP__
#define __FELIDE_SYSTEM_LIBRARY_HPP__

#include "felide/Config.hpp"
#include <felide/system/Module.hpp>

namespace felide { namespace system {
	/**
	 * @brief Dynamically loaded executable module library (.so on Unix, .dll on Windows)
	 */
	class FELIDE_API Library : public Module {
	public:
		virtual ~Library();
	};
}}

#endif
