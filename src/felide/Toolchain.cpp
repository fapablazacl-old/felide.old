
#include "Toolchain.hpp"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace felide {
	void Toolchain::build(ProjectItem *item) {
		fs::path tempPath = fs::temp_directory_path();
	}
}
