/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_PROJECTITEM_HPP__
#define __FELIDE_PROJECTITEM_HPP__

#include "Config.hpp"
#include <memory>
#include <string>

namespace felide { 
    class FELIDE_API ProjectItem {
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
