/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#if defined(__linux__)

#include "Process.hpp"

namespace felide { namespace system {
    
	class ProcessWin32 : public Process {
	public:
		ProcessWin32(ProcessFlags::Enum flags, const std::string &name) {
		}

		ProcessWin32(ProcessFlags::Enum flags, const std::string &name, const std::list<std::string> &args) {
		}
        
		virtual ~ProcessWin32() {
		}

		virtual int getExitCode() const override {
			return 0;
		}

		virtual void wait() override {
            
		}

		virtual void start() override {
		}

		virtual void terminate() override {
		}

		virtual std::string getOutput() const override {
			return "";
		}

	private:
		
	};
    
	ProcessPtr Process::open(ProcessFlags::Enum flags, const std::string &processName) {
		return ProcessPtr();
	}

	ProcessPtr Process::open(ProcessFlags::Enum flags, const std::string &processName, const std::list<std::string> &args) {
		return ProcessPtr();
	}
}}

#endif
