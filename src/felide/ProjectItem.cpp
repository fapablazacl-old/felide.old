/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#include "ProjectItem.hpp"

#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <boost/filesystem.hpp>

namespace felide {
    struct ProjectItem::Private {
        std::string path;
        bool modified = false;

        ProjectItemSignal modifiedSignal;
    };

    ProjectItem::ProjectItem() {
        m_impl = new ProjectItem::Private();

        this->new_();
    }
    
    ProjectItem::ProjectItem(const std::string &path) {
        m_impl = new ProjectItem::Private();

        this->new_();
        this->setPath(path);
    }
    
    ProjectItem::~ProjectItem() {
        delete m_impl;
    }
    
    ProjectItemSignal* ProjectItem::getModifiedSignal() {
        assert(m_impl);

        return &m_impl->modifiedSignal;
    }

    void ProjectItem::setModifyFlag(const bool modifyFlag) {
        assert(m_impl);

        if (m_impl->modified != modifyFlag) {
            m_impl->modified = modifyFlag;
            m_impl->modifiedSignal(this);
        }
    }
    
    bool ProjectItem::getModifyFlag() const {
        assert(m_impl);

        return m_impl->modified;
    }
    
    std::string ProjectItem::open() {
        assert(m_impl);

        typedef std::istreambuf_iterator<char> fstream_iterator;

        std::string line;
        std::string content;
        
        std::fstream fs;
        
        fs.open(this->getPath().c_str(), std::ios_base::in);
        if (!fs.is_open()) {
            throw std::runtime_error("");
        }

        content.assign(fstream_iterator(fs), fstream_iterator());

        m_impl->modified = false;
        
        return content;
    }
    
    std::string ProjectItem::open(const std::string &filename) {
        assert(m_impl);

        this->setPath(filename);
        return this->open();
    }
    
    void ProjectItem::save(const std::string &content) {
        assert(m_impl);

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
        
        m_impl->modified = false;
    }
    
    void ProjectItem::save(const std::string &content, const std::string &path) {
        assert(m_impl);

        this->setPath(path);
        this->save(content);
    }
    
    void ProjectItem::setPath(const std::string &path) {
        assert(m_impl);

        m_impl->path = path;
    }

    std::string ProjectItem::getPath() const {
        assert(m_impl);

        return m_impl->path;
    }
    
    bool ProjectItem::hasPath() const {
        assert(m_impl);

        return m_impl->path.size() > 0;
    }
    
    std::string ProjectItem::getName() const {
        assert(m_impl);

        if (this->hasPath()) {
            return boost::filesystem::path(this->getPath()).filename().string();
        } else {
            return "";
        }
    }
    
    void ProjectItem::new_() {
        assert(m_impl);

        this->setPath("");
        m_impl->modified = false;
    }
}
