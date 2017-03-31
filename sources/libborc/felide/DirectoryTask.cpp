
#include "DirectoryTask.hpp"

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

namespace fs = boost::filesystem;

namespace borc {
    DirectoryTask::DirectoryTask(const std::string &directory) : m_directory(directory) {}

    void DirectoryTask::perform() {
        // TODO: Handle error

        fs::path path(m_directory);
        fs::create_directories(path);
    }
}
