/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_SYSTEM_MODULE_HPP__
#define __FELIDE_SYSTEM_MODULE_HPP__

#include <string>

namespace felide { namespace system {
	/**
	 * @brief OS-dependent handle.
	 */
	typedef void* ModuleHandlePtr;
	
	/**
	 * @brief Executable module image. 
	 */
	class Module {
	public:
		virtual ~Module();
		
		/**
		 * @brief Get the pointer of the speficied function filename.
		 *
		 * If no such function exist, exception std::runtime_error is thrown.
		 */
		virtual void* getFunction(const std::string &name) = 0;
		
		/**
		 * @brief Get the pointer of the speficied function filename.
		 *
		 * If no such function exist, exception std::runtime_error is thrown.
		 */
		virtual const void* getFunction(const std::string &name) const = 0;
		
		/**
		 * @brief Get the operating system dependent module handle. 
		 *
		 * If the module was not properly loaded, it returns a nullptr.
		 */
		virtual const ModuleHandlePtr getHandle() const = 0;
	};
}}

#endif	//__FELIDE_PROTO_SYSTEM_MODULE_HPP__
