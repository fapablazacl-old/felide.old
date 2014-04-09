/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_FILEUTIL_HPP__
#define __FELIDE_FILEUTIL_HPP__

#include <string>

namespace felide { namespace util {
    
	/**
	 * @brief Static class for basic file management utilities.
	 */
	class FileUtil {
	private:
		FileUtil();
		
	public:
		/**
		 * @brief Load a string from the specified file.
		 *
		 * If the file doesn't exists, or can't be openened, 
		 * throws std::runtime_exception.
		 */
		static std::string load(const std::string &file);
		
		/**
		 * @brief Save a string on the specified file.
		 *
		 * If the specified file doesn't exists, this function create a new one, and put the 
		 * content on it. 
		 *
		 * If the specified file already exists, the method replaces completly 
		 * all the previously saved content with the new one. 
		 *
		 * If the specified file can't be accessed, a std::runtime_error exception is thrown.
		 */
		static void save(const std::string &file, const std::string &content);
	};	
}}

#endif	//__FELIDE_FILEUTIL_HPP__
