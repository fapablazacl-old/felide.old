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

#include <stdio.h>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/trim_all.hpp>


namespace felide { namespace system {
    
	class ProcessUnix : public Process {
	public:
		ProcessUnix(ProcessFlags::Enum flags, const std::string &name) {
            this->construct(flags, name, {});
		}

		ProcessUnix(ProcessFlags::Enum flags, const std::string &name, const std::list<std::string> &args) {
            this->construct(flags, name, args);
		}
        
        void construct(ProcessFlags::Enum flags, const std::string &name, const std::list<std::string> &args) {
            std::string command = name  + " " + boost::algorithm::join(args, " ");
            
            boost::algorithm::trim_all(command);
            
            m_command = command;
        }
        
		virtual ~ProcessUnix() {
            if (m_handle) {
                pclose(m_handle);
            }
		}

		virtual int getExitCode() const override {
			return m_exitCode;
		}

		virtual void wait() override {
            
		}

		virtual void start() override {
            m_handle = popen(m_command.c_str(), "r");
            
            const int buffer_length = 256;
            char buffer[buffer_length];
            
            while (m_handle && !feof(m_handle)) {
                if (fgets(buffer, buffer_length, m_handle)) {
                    m_output += buffer;
                }
            }
		}

        virtual void terminate() override {
            
		}

		virtual std::string getOutput() const override {
			return "";
		}

	private:
        std::string m_command;
        std::string m_output;
        int m_exitCode = 0;
        FILE *m_handle = nullptr;
	};
    
	ProcessPtr Process::open(ProcessFlags::Enum flags, const std::string &processName) {
		return std::make_unique<ProcessUnix>(flags, processName);
	}

	ProcessPtr Process::open(ProcessFlags::Enum flags, const std::string &processName, const std::list<std::string> &args) {
		return std::make_unique<ProcessUnix>(flags, processName, args);
	}
}}

#endif
