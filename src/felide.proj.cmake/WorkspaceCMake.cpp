
#include "WorkspaceCMake.hpp"

#include <iostream>
#include <boost/format.hpp>

namespace felide {

    WorkspaceCMake::WorkspaceCMake() {
        m_cmakelists_path = fs::path("/home/fapablaza/Desktop/Projects/felide/CMakeLists.txt");
        m_build_paths.push_back("/home/fapablaza/Desktop/Projects/felide/build.debug");
    }

    std::string WorkspaceCMake::getPath() const {
        
        std::string path = m_cmakelists_path.parent_path().string();
        
        return path;
    }
    
    int WorkspaceCMake::getProjectCount() const {
        return 0;
    }
    
    Project* WorkspaceCMake::getProject(int i) {
        return nullptr;
    }
    
    const Project* WorkspaceCMake::getProject(int i) const {
        return nullptr;
    }
    
    void WorkspaceCMake::addProject(ProjectPtr project)  {
        
    }
    
    void WorkspaceCMake::removeProject(ProjectPtr project)  {
        
    }
    
    void WorkspaceCMake::deleteProject(ProjectPtr project) {
        
    }
    
    void WorkspaceCMake::build() {
        fs::path build_path = m_build_paths[m_default_build];
        
        std::list<std::string> commands = {
            "cd " + build_path.string(),
            "make"
        };
        
        this->execute(commands);
    }
    
    void WorkspaceCMake::buildAll() {
        std::cout << "WorkspaceCMake::buildAll: Not implemented!" << std::endl;
    }
}
