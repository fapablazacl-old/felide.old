/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_SYSTEM_ENVIRONMENT_HPP__
#define __FELIDE_SYSTEM_ENVIRONMENT_HPP__

#include <string>

namespace felide { namespace system {
	/**
	* @brief Accessor and manipulator for temporal environment variables of processes.
	 */
	class Environment {
	public:
		virtual ~Environment();
		
		/**
		 * @brief Gets the total variable count of the environment accesor/manipulator.
		 */
		virtual int getVariableCount() const = 0;
		
		/**
		 * @brief Gets the variable name located at the specified index. 
		 * 
		 * That index will be interpreted as an zero-based index. 
		 * If no such location exist, exception std::runtime_error is thrown.
		 */
		virtual std::string getVariable(const int index) const = 0;
		
		/**
		 * @brief Gets the variable value located at the specified index. 
		 *
		 * If no such location exist, exception std::runtime_error is thrown.
		 */
		virtual std::string getVariableValue(const int index) const = 0;
		
		/**
		 * @brief Gets the value of the specified variable.
		 *
		 * If no such variable exist, exception std::runtime_error is thrown.
		 */
		virtual std::string getVariableValue(const std::string &variableName) const = 0;
		
		/**
		 * @brief Sets the value of the specified variable. 
		 *
		 * If the variable previously exists, the old value is replaced with the new one. 
		 * If no such variable exist, a new environment variable its created with a empty string value, and 
		 * located at the 'Environment::getValueCount' zero-based position.
		 */
		virtual void setVariableValue(const std::string &variableName, const std::string &variableValue) = 0;
		
		/**
		 * @brief 
		 * 
		 * 
		 */
		virtual void appendVariableValue(const std::string &variableName, const std::string &variableValue) = 0;
	};
}}

#endif	// __FELIDE_PROTO_SYSTEM_ENVIRONMENT_HPP__
