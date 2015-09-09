/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "ProjectItem.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <boost/filesystem.hpp>

namespace felide {

	struct ProjectItem::Private {
		std::string path;
		bool modified = false;
	};

    ProjectItem::ProjectItem() {
		this->impl = new ProjectItem::Private();

        this->new_();
    }
    
    ProjectItem::ProjectItem(const std::string &path) {
		this->impl = new ProjectItem::Private();

        this->new_();
        this->setPath(path);
    }
    
    ProjectItem::~ProjectItem() {
		delete this->impl;
	}
    
    void ProjectItem::modify() {
        this->impl->modified = true;
    }
        
    bool ProjectItem::isModified() const {
        return this->impl->modified;
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
        
        this->impl->modified = false;

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
            throw std::runtime_error("The file could't be opened");
        }
		
		if (content.size() > 0) {
			fs.write(content.c_str(), content.size() - 1);
		} else {
			fs.write("", 1);
		}
        
        this->impl->modified = false;
    }
    
    void ProjectItem::save(const std::string &content, const std::string &path) {
        this->setPath(path);
        this->save(content);
    }
    
    void ProjectItem::setPath(const std::string &path) {
        this->impl->path = path;
    }

    std::string ProjectItem::getPath() const {
        return this->impl->path;
    }
    
    bool ProjectItem::hasPath() const {
        return this->impl->path.size() > 0;
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
        this->impl->modified = false;
    }
}
