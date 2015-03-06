
#include "ProjectItem.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace felide { namespace model {
    
    ProjectItem::ProjectItem() {}
    
    ProjectItem::ProjectItem(const std::string &path) 
    {
        this->setPath(path);
    }
    
    ProjectItem::~ProjectItem() {}
    
    void ProjectItem::setDirtyFlag(bool flag) 
    {
        this->dirty = flag;
    }
        
    bool ProjectItem::getDirtyFlag() const 
    {
        return this->dirty;
    }
    
    std::string ProjectItem::load() 
    {
        std::string line;
        std::string content;
        
        std::fstream fs;
        
        fs.open(this->getPath().c_str(), std::ios_base::in);
        if (!fs.is_open()) {
            throw std::runtime_error("");
        }
        
        while (!fs.eof()) {
            std::getline(fs, line);
            
            content += line;
            content += "\n";
        }
        
        this->dirty = false;
        
        return content;
    }
    
    void ProjectItem::save(const std::string &content) 
    {
        std::fstream fs;
        
        fs.open(this->getPath().c_str(), std::ios_base::out);
        if (!fs.is_open()) {
            throw std::runtime_error("");
        }
        
        fs << content;
        
        this->dirty = false;
    }
    
    void ProjectItem::setPath(const std::string &path) 
    {
        this->path = path;
    }

    std::string ProjectItem::getPath() const 
    {
        return this->path;
    }
    
    bool ProjectItem::hasPath() const 
    {
        return this->path.size() > 0;
    }
}}
