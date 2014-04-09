/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */
 
#include <felide/projects/ProjectItem.hpp>

namespace felide { namespace projects {
	class ProjectItem::Private {
    public:
		std::string file;
	};
	
	ProjectItem::ProjectItem(const std::string &file) : impl(new ProjectItem::Private()) {
	}
	
	ProjectItem::~ProjectItem() {
	}
	
	std::string ProjectItem::getFile() const {
		assert(this->impl != nullptr);
		return this->impl->file;
	}
	
	void ProjectItem::setFile(const std::string &file) {
		assert(this->impl != nullptr);
        this->impl->file = file;
    }
    
    bool ProjectItem::hasValidFile() const {
        assert(this->impl != nullptr);
        
        // TODO: Add a path validation based on the current OS class.
        if (this->impl->file.size()==0) {
            return false;
        } else {
            return true;
        }
    }
}}
