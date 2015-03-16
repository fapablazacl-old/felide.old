
#if 0

#include "Source.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace felide { namespace model {
    
    Source::Source() {}
    
    Source::Source(const std::string &path) 
    {
        this->setPath(path);
    }
    
    Source::~Source() {}
    
    void Source::setDirtyFlag(bool flag) 
    {
        this->dirty = flag;
    }
        
    bool Source::getDirtyFlag() const 
    {
        return this->dirty;
    }
    
    std::string Source::load() 
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
    
    void Source::save(const std::string &content) 
    {
        std::fstream fs;
        
        fs.open(this->getPath().c_str(), std::ios_base::out);
        if (!fs.is_open()) {
            throw std::runtime_error("");
        }
        
        fs << content;
        
        this->dirty = false;
    }
    
    void Source::setPath(const std::string &path) 
    {
        this->path = path;
    }

    std::string Source::getPath() const 
    {
        return this->path;
    }
    
    bool Source::hasPath() const 
    {
        return this->path.size() > 0;
    }
}}

#endif
