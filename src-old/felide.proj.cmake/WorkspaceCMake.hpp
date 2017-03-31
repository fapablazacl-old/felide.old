
#pragma once

#ifndef __felide_workspacecmake_hpp__
#define __felide_workspacecmake_hpp__

#include <boost/filesystem/path.hpp>
#include <vector>

#include "felide_old/Workspace.hpp"

namespace felide {

    namespace fs = boost::filesystem;
    
    /**
     * @brief Workspace implementation using the CMake build system
     */
    class WorkspaceCMake : public Workspace {
    public:
        WorkspaceCMake();
        
        virtual int getProjectCount() const override;
        virtual Project* getProject(int i) override;
        virtual const Project* getProject(int i) const override;
        
        virtual void addProject(ProjectPtr project)  override;
        virtual void removeProject(ProjectPtr project)  override;
        virtual void deleteProject(ProjectPtr project)  override;
        
        virtual void setName(const std::string &name)  override {
            m_name = name;
        }
        
        virtual std::string getName() const override {
            return m_name;
        }
        
        virtual std::string getPath() const override;
        
        void build();
        
        void buildAll();
        
        
    private:
        std::string m_name;
        fs::path m_cmakelists_path;             //! Main CMakeLists.txt file full path.
        std::vector<fs::path> m_build_paths;    //! Build directories for this workspace
        int m_default_build = 0;                //! Default build directory index
    };        
}

#endif 
