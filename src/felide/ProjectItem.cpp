
#include "ProjectItem.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <boost/filesystem.hpp>

namespace felide {

    ProjectItem::ProjectItem() {
        this->new_();
    }
    
    ProjectItem::ProjectItem(const std::string &path) {
        this->new_();
        this->setPath(path);
    }
    
    ProjectItem::~ProjectItem() {}
    
    void ProjectItem::modify() {
        this->modified = true;
    }
        
    bool ProjectItem::isModified() const {
        return this->modified;
    }
    
    std::string ProjectItem::open() {
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
            content += "\r\n";
        }
        
        this->modified = false;

        return content;
    }
    
    std::string ProjectItem::open(const std::string &filename) {
        this->setPath(filename);
        return this->open();
    }
    
    void ProjectItem::save(const std::string &content) {
        std::fstream fs;
        
        fs.open(this->getPath().c_str(), std::ios_base::out);
        if (!fs.is_open()) {
            throw std::runtime_error("");
        }
        
        fs << content;
        
        this->modified = false;
    }
    
    void ProjectItem::save(const std::string &content, const std::string &path) {
        this->setPath(path);
        this->save(content);
    }
    
    void ProjectItem::setPath(const std::string &path) {
        this->path = path;
    }

    std::string ProjectItem::getPath() const {
        return this->path;
    }
    
    bool ProjectItem::hasPath() const {
        return this->path.size() > 0;
    }
    
    std::string ProjectItem::getName() const {
        if (this->hasPath()) {
            return boost::filesystem::path(this->getPath()).filename().string();
        } else {
            return "";
        }
    }
    
    void ProjectItem::new_() {
        this->setPath("");
        this->modified = false;
    }
}
