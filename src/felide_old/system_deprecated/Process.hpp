/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_SYSTEM_PROCESS_HPP__
#define __FELIDE_SYSTEM_PROCESS_HPP__

#include "felide/Config.hpp"
#include <string>
#include <list>
#include <memory>
#include <functional>

namespace felide { namespace system {

    /**
     * @brief Possible status for a given Process.
     */
    struct ProcessStatus {
        enum Enum {
            Stopped,     //! The process has not begun, or has been terminated.
            Executing     //! The process is currently executing.
        };
    }; 

    class Process;
    typedef std::unique_ptr<Process> ProcessPtr;

    typedef std::function<void (const std::string &)> ProcessCallback;


    struct ProcessFlags {
        enum Enum {
            Default = 0,
            Redirect = 1
        };
    };

    /**
     * @brief External OS process.
     */
    class FELIDE_API Process {
    public:
        virtual ~Process() {}
        
        /**
         * @brief Get the process exit code.
         */
        virtual int getExitCode() const = 0;

        /**
         * @brief Wait for execution
         */
        virtual void wait() = 0;

        /**
         * @brief Get process output
         */
        virtual std::string getOutput() const = 0;

        /** 
         * @brief Start in async the process.
         */
        virtual void start() = 0;

        virtual void terminate() = 0;

    public:
        static ProcessPtr open(ProcessFlags::Enum flags, const std::string &processName);
        static ProcessPtr open(ProcessFlags::Enum flags, const std::string &processName, const std::list<std::string> &args);
    };
}}

#endif
