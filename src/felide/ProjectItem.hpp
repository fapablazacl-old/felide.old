
#ifndef __FELIDE_PROJECTITEM_HPP__
#define __FELIDE_PROJECTITEM_HPP__

#include <memory>
#include <string>

namespace felide { 
    class ProjectItem {
    public:
        ProjectItem();
        
        explicit ProjectItem(const std::string &path);
        
        ~ProjectItem();
        
        //! Sets the modification flag to 'true'
        void modify();
        
        //! Get the current modification flag
        bool isModified() const;
        
        //! Open the current file. Throws a std::runtime_error exception if the ProjectItem has no file associated.
        std::string open();
        
        //! Open the specified file.
        std::string open(const std::string &path);
        
        void save(const std::string &content);
        void save(const std::string &content, const std::string &path);
        
        bool hasPath() const;
        void setPath(const std::string &path);

        std::string getPath() const;
        
        std::string getName() const;
        
        void new_();
        
    private:
        std::string path;
        bool modified = false;
    };
    
    typedef std::unique_ptr<ProjectItem> ProjectItemPtr;
}

#endif	// __FELIDE_PROJECTITEM_HPP__
