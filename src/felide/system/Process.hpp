/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_SYSTEM_PROCESS_HPP__
#define __FELIDE_SYSTEM_PROCESS_HPP__

#include <felide/system/Module.hpp>
#include <list>

namespace felide { namespace system {
	/**
	 * @brief Possible status for a given Process.
	 */
	struct ProcessStatus {
		enum Enum {
			Stopped, 	/** @brief The process has not begun, or has been terminated. */
			Executing 	/** @brief The process is currently executing. */
		};
	}; 

	class Environment;

	/**
	 * @brief Executable process module pointer reference.
	 */
	class Process : public Module {
	public:
		Process ();
		virtual ~Process();
		
		void open(const std::string &processName);
		void open(const std::string &processName, const std::list<std::string> &args);
		void close();
		void start();
		void terminate();
		
		void setInputStream(std::istream &is);
		void setOutputStream(std::ostream &os);
		void setErrorStream(std::ostream &os);
		
		std::istream& getInputStream();
		std::ostream& getOutputStream();
		std::ostream& getErrorStream();
		
		const std::istream& getInputStream() const;
		const std::ostream& getOutputStream() const;
		const std::ostream& getErrorStream() const;
		
		Environment* getEnvironment();
		const Environment* getEnvironment() const;

		/**
		 * @brief Get the exit code of the process.
		 *
		 * In case the process is still running, the caller get hanged-up until the first one
		 * terminates execution.
		 */
		int getExitCode() const;
		
		/**
		 * @brief Get the execution status for the process.
		 */
		ProcessStatus::Enum getStatus() const;
		
	public:
		/**
		 * @brief Get a pointer reference to the currently running process.
		 */
		static Process* getCurrent();
		
	private:
		class Private;
		Private *impl;
	};
}}

#endif
