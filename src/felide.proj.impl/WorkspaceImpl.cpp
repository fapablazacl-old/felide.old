
#include <list>

#include "felide/Workspace.hpp"

namespace felide {

    class ProjectImpl : public Project {
    public:
        
    };
    
    
    typedef std::unique_ptr<ProjectImpl> ProjectImplPtr;
    
    
    class WorkspaceImpl : public Workspace {
        virtual int getProjectCount() const override;
        virtual Project* getProject(int i) override;
        virtual const Project* getProject(int i) const override;
        
        virtual void addProject(ProjectPtr project) override;
        virtual void removeProject(ProjectPtr project) override;
        virtual void deleteProject(ProjectPtr project) override;
        
        virtual std::string getName() const override;
        virtual void setName(const std::string &name) override;

    private:
        std::list<ProjectImplPtr> m_projects;
    };        
}
