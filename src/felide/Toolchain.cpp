/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "Toolchain.hpp"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace felide {
	void Toolchain::build(ProjectItem *item) {
		fs::path tempPath = fs::temp_directory_path();
	}
}
