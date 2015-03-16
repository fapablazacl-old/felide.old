
#if 0

#ifndef __FELIDE_MODEL_SOURCE_HPP__
#define __FELIDE_MODEL_SOURCE_HPP__

#include <string>

namespace felide { namespace model {
    
    class Source {
    public:
        Source();
        
        explicit Source(const std::string &path);
        
        ~Source();
        
        void setDirtyFlag(bool flag);
        
        bool getDirtyFlag() const;
        
        std::string load();
        
        void save(const std::string &content);
        
        bool hasPath() const;
        
        void setPath(const std::string &path);

        std::string getPath() const;
        
    private:
        std::string path;
        bool dirty = false;
    };
}}

#endif  // __FELIDE_MODEL_SOURCE_HPP__

#endif
