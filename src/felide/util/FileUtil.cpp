/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */
 
#include <felide/util/FileUtil.hpp>

#include <fstream>
#include <stdexcept>

namespace felide { namespace util {
	
	std::string FileUtil::load(const std::string &file) {
		std::string line;
		std::string content;
		std::fstream fs;
		fs.open(file, std::ios_base::in);
        
        // TODO: Check the exact reason for the failed file open operation.
		if (fs.is_open() == false) {
            std::string message;
            message += "felide::util::FileUtil::load: The file ";
            message += "'" + file + "'";
            message += "cannot be open for read operations, or it doesn't exists.";
            
			throw std::runtime_error(message);
		}
		
		// concatenate line by line
		// TODO: Read by one chunk, to avoid unnecesary memory fragmentation on large files.
		while (std::getline(fs, line)) {
			content += line;
		}
		
		return content;
	}
	
	
	void FileUtil::save(const std::string &file, const std::string &content) {
		std::fstream fs;
		fs.open(file, std::ios_base::out);
        
        // TODO: Check the exact reason for the failed file open operation.
		if (fs.is_open() == false) {
            std::string message;
            message += "felide::util::FileUtil::save: The file ";
            message += "'" + file + "'";
            message += "cannot be open for write operations.";
            
			throw std::runtime_error(message);
		}
		
		fs.write(content.c_str(), content.size());
	}
}}
