/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_MODEL_PROJECT_HPP__
#define __FELIDE_MODEL_PROJECT_HPP__

#include <string>
#include <memory>

#include "felide/ProjectItem.hpp"
#include "felide/Collection.hpp"

namespace felide { 
    class FELIDE_API Project {
    public:
        virtual ~Project() = 0;
        
        virtual int getItemCount() const = 0;
        virtual ProjectItem* getItem(int index) = 0;
        virtual const ProjectItem* getItem(int index) const = 0;
        
        virtual void addItem(const ProjectItem &item) = 0;
        virtual void removeItem(const ProjectItem &item) = 0;
        virtual void deleteItem(ProjectItem item) = 0;
    };
    
    typedef std::unique_ptr<Project> ProjectPtr;
}

#endif    // __FELIDE_MODEL_PROJECT_HPP__
