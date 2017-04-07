
#include "ToolChainCpp.hpp"
#include "CommandTask.hpp"
#include "DirectoryTask.hpp"

#include <map>
#include <set>
#include <cassert>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/case_conv.hpp>

#include <boost/range/algorithm/transform.hpp>
#include <boost/range/algorithm_ext/insert.hpp>

namespace fs = boost::filesystem;
namespace rng = boost::range;

namespace borc {
    
    /**
     * @brief C/C++ file type 
     */
    enum class CppFileType {
        Unknown,
        Source, 
        Header
    };
    
    /**
     * @brief Wrapper for boost::filesystem::path class. Used in the boost::range algorithms 
     */
    inline fs::path make_path(const std::string &path) {
        return fs::path(path);
    }
    
    struct ToolChainCpp::Private {
    public:
        ToolChainInfo m_info;
        
        std::string m_installPath;
        
        Compiler m_compiler;
        Linker m_linker;
        Librarian m_librarian;
        
        std::vector<std::string> m_compilerFlags;
        std::vector<std::string> m_linkerFlags;
        
        std::vector<fs::path> m_includePaths;
        std::vector<fs::path> m_libraryPaths;
        
        std::set<std::string> m_headers;
        
        std::set<std::string> m_sources;
        
    public:
        Private() {
            m_headers = std::set<std::string>({
                ".h", ".hpp", ".hxx", ".h++", ".hh"
            });
            
            m_sources = std::set<std::string>({
                ".c", ".cpp", ".cxx", ".c++", ".cc"
            });
        }
        
        /**
         * @brief Get the C++ file type for the specified file name
         */
        CppFileType getFileType(const fs::path &filePath) {
            const std::string ext = boost::to_lower_copy(filePath.extension().string());
            
            if (m_headers.find(ext) != m_headers.end()) {
                return CppFileType::Header;
            } else if (m_sources.find(ext) != m_sources.end()) {
                return CppFileType::Source;
            } else {
                return CppFileType::Unknown;
            }
        }
        
        /**
         * @brief Generate the corresponding object file name for the source file
         */ 
        fs::path genObjectFile(const fs::path &sourceFile) {
            return sourceFile.string() + ".obj";
        }
        
        /**
         * @brief Generates additional compile options for include directories specified in the target source
         */
        std::vector<std::string> genIncludeOpts(const std::vector<fs::path> &includes, const fs::path &parentPath="") {
            std::vector<std::string> options;
            
            for (const fs::path &includePath : includes) {
                const fs::path includeOption = parentPath / includePath;
                options.push_back(m_compiler.additionalIncludePath + includeOption.string());
            }
            
            return options;
        }
        
        /**
         * @brief Generates additional compile options for include directories specified in the target source
         */
        std::vector<std::string> genLibraryPathFlags(const std::vector<fs::path> &libraryPaths) {
            std::vector<std::string> result;
            
            rng::transform(libraryPaths, std::back_inserter(result), [&](const fs::path &path) {
                return m_linker.additionalLibraryPath + path.string();
            });
            
            return result;
        }
        
        /**
         * @brief Generate the Build Command to compile to object file the specified source file.
         */
        std::unique_ptr<Task> genTask(const fs::path &file, const std::vector<std::string> &otherArgs, const fs::path &sourcePath, const fs::path& buildPath) {
            if (getFileType(file) != CppFileType::Source) {
                return std::unique_ptr<Task>();
            }
            
            std::vector<std::string> taskArgs;
    
            std::string args[] = {
                (sourcePath / file).string(), 
                m_compiler.compile, 
                m_compiler.outputFile + genObjectFile((buildPath/file)).string()
            };
            
            rng::insert(taskArgs, taskArgs.begin(), args);
            rng::insert(taskArgs, taskArgs.begin(), otherArgs);
            
            return std::make_unique<CommandTask>(m_compiler.command, taskArgs);
        }
        
        /**
         * @brief Generate the list of commands to build a C/C++ software component.
         */
        std::vector<std::unique_ptr<Task>> genTasks(const Target &target, const fs::path &basePath, const fs::path &buildPath) {
            std::vector<fs::path> targetIncludes;
            
            rng::transform(target.includes, std::back_inserter(targetIncludes), make_path);
            
            const auto targetPath = basePath / target.path;
            const auto targetIncludeFlags = genIncludeOpts(targetIncludes, targetPath);
            const auto includeFlags = genIncludeOpts(m_includePaths);
    
            std::vector<std::string> opts;
            
            rng::insert(opts, opts.begin(), targetIncludeFlags);
            rng::insert(opts, opts.begin(), includeFlags);
            rng::insert(opts, opts.begin(), m_compilerFlags);
    
            std::vector<std::unique_ptr<Task>> tasks;

            // build commands for creating required directories for the generated object files
            rng::transform(target.items, std::back_inserter(tasks), [&](const item &item) {
                fs::path directory = buildPath / item.file;
                
                return std::make_unique<DirectoryTask>(directory.parent_path().string());
            });

            // build commands for every item in the current target
            rng::transform(target.items, std::back_inserter(tasks), [&](const item &item) {
                return this->genTask(item.file, opts, targetPath, buildPath);
            });
            
            // target build tool
            std::string taskCommand;
            
            if (target.type == TargetType::Executable) {
                taskCommand = m_linker.command;
            } else if (target.type == TargetType::Library) {
                taskCommand = m_librarian.command;
            }
            
            // target generated object files
            std::vector<std::string> taskArgs;
            
            for (const item &item : target.items) {
                fs::path itemFile = item.file;
                
                CppFileType type = getFileType(item.file);

                if (type == CppFileType::Source) {
                    fs::path itemPath = buildPath / itemFile;

                    taskArgs.push_back(genObjectFile(itemPath).string());
                }
            }
            
            // output file flag
            std::string outputFileFlag;
            
            std::string targetBuildPath = (buildPath / target.name).string();
            
            if (target.type == TargetType::Executable) {
                outputFileFlag = m_linker.outputFile + targetBuildPath + m_linker.ext;
            } else if (target.type == TargetType::Library) {
                outputFileFlag = m_librarian.outputFile + targetBuildPath + m_librarian.ext;
            }
            
            taskArgs.push_back(outputFileFlag);
            
            if (target.type == TargetType::Executable) {
                // library paths for executable and dynamic link libraries
                const auto libraryPathFlags = genLibraryPathFlags(m_libraryPaths);
                
                rng::insert(taskArgs, taskArgs.begin(), libraryPathFlags);
                rng::insert(taskArgs, taskArgs.begin(), m_linkerFlags);
                
                tasks.push_back(std::make_unique<CommandTask>(taskCommand, taskArgs));
            }
            
            return tasks;
        }
    };
    
    ToolChainCpp::ToolChainCpp (
            const ToolChainInfo &info, 
            const std::string &installPath, 
            const Compiler &compiler,
            const Linker &linker,
            const Librarian &librarian,
            const std::vector<std::string> &compilerFlags, 
            const std::vector<std::string> &linkerFlags, 
            const std::vector<std::string> &includePaths,
            const std::vector<std::string> &libraryPaths) : m_impl(new ToolChainCpp::Private()) {

        assert(m_impl);
        
        m_impl->m_info = info;
        m_impl->m_compiler = compiler;
        m_impl->m_linker = linker;
        m_impl->m_librarian = librarian;
        m_impl->m_compilerFlags = compilerFlags;
        m_impl->m_linkerFlags = linkerFlags;
        
        rng::transform(includePaths, std::back_inserter(m_impl->m_includePaths), make_path);
        
        rng::transform(libraryPaths, std::back_inserter(m_impl->m_libraryPaths), make_path);
    }
    
    ToolChainCpp::~ToolChainCpp() {
        assert(m_impl);
        
        delete m_impl;
    }
    
    ToolChainInfo ToolChainCpp::getInfo() const {
        assert(m_impl);
        
        return m_impl->m_info;
    }
    
    std::vector<std::unique_ptr<Task>> ToolChainCpp::generateBuildTasks(const Project &project) {
        assert(m_impl);
        
        std::vector<std::unique_ptr<Task>> tasks;
        
        auto buildPath = fs::path(project.path) / ".borc";
        auto dirTask = std::make_unique<DirectoryTask>(buildPath.string());

        tasks.push_back(std::move(dirTask));
        
        for (const Target &target : project.targets) {
            auto targetTasks = m_impl->genTasks(target, project.path, buildPath);
            
            std::move(targetTasks.begin(), targetTasks.end(), std::back_inserter(tasks));
        }

        return tasks;
    }
}
