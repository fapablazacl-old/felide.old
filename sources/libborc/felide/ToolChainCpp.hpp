
/**
 * @brief Generator 
 */

#pragma once

#ifndef __borc_toolchaincpp_hpp__
#define __borc_toolchaincpp_hpp__

#include "ToolChain.hpp"

#include <vector>
#include <string>

namespace borc {
    
    /**
     * @brief Compiler toolchain switche desc
     */ 
    struct Compiler {
        std::string command;                //! Name of the compiler command tool
        std::string compile;                //! Compile command
        std::string additionalIncludePath;  //! Include directory command
        std::string outputFile;             //! Output filename switch
    };
    
    /**
     * @brief Linker toolchain switch desc
     */ 
    struct Linker {
        std::string command;                //! Name of the linker command tool
        std::string additionalLibraryPath;  //! Library path cmdline switch
        std::string outputFile;             //! Output filename switch
        std::string ext;                    //! Filename extension
    };
    
    /**
     * @brief Libraruab tool switch desc (for generating static libraries)
     */
    struct Librarian {
        std::string command;                //! name of the librarian command tool
        std::string outputFile;             //! Output filename switch
        std::string ext;                    //! Filename extension
    };
    
    /**
     * @brief ToolChain class for C/C++ projects
     */ 
    class ToolChainCpp : public ToolChain {
    public:
        ToolChainCpp (
                const ToolChainInfo &info, 
                const std::string &installPath, 
                const Compiler &compiler,
                const Linker &linker,
                const Librarian &librarian,
                const std::vector<std::string> &compilerFlags, 
                const std::vector<std::string> &linkerFlags, 
                const std::vector<std::string> &includePaths,
                const std::vector<std::string> &libraryPaths);

        virtual ~ToolChainCpp();
        
        virtual ToolChainInfo getInfo() const override;

        virtual std::vector<std::unique_ptr<Task>> generateBuildTasks(const Project &project) override;

    private:
        struct Private;
        Private *m_impl = nullptr;
    };
}

#endif
