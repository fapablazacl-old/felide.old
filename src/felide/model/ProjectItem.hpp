
#ifndef __FELIDE_MODEL_PROJECTITEM_HPP__
#define __FELIDE_MODEL_PROJECTITEM_HPP__

#include <string>

namespace felide { namespace model {
    
    class ProjectItem {
    public:
        ProjectItem();
        
        explicit ProjectItem(const std::string &path);
        
        ~ProjectItem();
        
        void setDirtyFlag(bool flag);
        
        bool getDirtyFlag() const;
        
        std::string open();
        std::string open(const std::string &filename);
        
        void save(const std::string &content);
        void save(const std::string &content, const std::string &filename);
        
        bool hasPath() const;
        void setPath(const std::string &path);

        std::string getPath() const;
        
        std::string getName() const;
        
        void new_();
        
    private:
        std::string path;
        bool dirty = false;
    };
}}

#endif	// __FELIDE_MODEL_PROJECTITEM_HPP__
