
#include <felide/Main.hpp>
#include <felide/ToolChainCpp.hpp>

#include <boost/program_options.hpp>

borc::Project createTestProject() {
    // sample test
    borc::Target target = {
        "ConsoleApp01",
        "samples/ConsoleApp01", 
        borc::TargetType::Executable,
        {
            {"include/ConsoleApp01.hpp"}, 
            {"src/ConsoleApp01.cpp"}
        },

        "include"
    };

    borc::Project project = {
        "ConsoleApp01", 
        "samples/ConsoleApp01", 
        target
    };


    return project;
}

borc::ToolChainCpp createToolChainGCC() {
    borc::ToolChainInfo info; 
    info.name = "GNU C/C++ Compiler";
    info.provider = "GNU Foundation";
    info.targetArch = borc::Arch::x86_64;
    info.version = borc::Version(1, 0, 0);
    
    std::string installPath = "/usr";
    
    borc::Compiler compiler;
    compiler.command = "gcc";
    compiler.additionalIncludePath = "-I";
    compiler.compile = "-c";
    compiler.outputFile = "-o";
    
    borc::Linker linker;
    linker.command = "gcc";
    linker.additionalLibraryPath = "-L";
    linker.outputFile = "-o";
    
    borc::Librarian librarian;
    librarian.command = "ar";
    librarian.ext = ".a";
    librarian.outputFile = "-o";
    
    std::vector<std::string> compilerFlags = {"-Wall", "-g", "-O0"};
    std::vector<std::string> linkerFlags = {"-lstdc++"};
    std::vector<std::string> includePaths;
    std::vector<std::string> libraryPaths;
    
    return borc::ToolChainCpp (
        info, 
        installPath, 
        compiler, 
        linker, 
        librarian, 
        compilerFlags, 
        linkerFlags, 
        includePaths, 
        libraryPaths        
    );
}

borc::ToolChainCpp createToolChainVC() {
    borc::ToolChainInfo info; 
    info.name = "Visual C++";
    info.provider = "Microsoft";
    info.targetArch = borc::Arch::x86_64;
    info.version = borc::Version(1, 0, 0);
    
    std::string installPath = "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC";
    std::string wndkitPath = "C:\\Program Files (x86)\\Windows Kits";
    
    borc::Compiler compiler;
    compiler.command = "cl";
    compiler.additionalIncludePath = "/I";
    compiler.compile = "/c";
    compiler.outputFile = "/Fo";
    
    borc::Linker linker;
    linker.command = "link";
    linker.additionalLibraryPath = "/LIBPATH:";
    linker.ext = ".exe";
    linker.outputFile = "/OUT:";
    
    borc::Librarian librarian;
    librarian.command = "lib";
    librarian.ext = ".lib";
    librarian.outputFile = "/OUT:";
    
    std::vector<std::string> compilerFlags = {"/EHsc"};
    std::vector<std::string> linkerFlags;

    std::vector<std::string> includePaths = {
        "\"" + installPath + "\\include\"",
        "\"" + installPath + "\\atlmfc\\include\"",
        "\"" + wndkitPath + "\\10\\Include\\10.0.10240.0\\ucrt\"",
        "\"" + wndkitPath + "\\8.1\\Include\\um\"",
        "\"" + wndkitPath + "\\8.1\\Include\\shared\"",
        "\"" + wndkitPath + "\\8.1\\Include\\winrt\""
    };

    std::vector<std::string> libraryPaths = {
        "\"" + installPath + "\\lib\\amd64\"",
        "\"" + wndkitPath + "\\8.1\\Lib\\winv6.3\\um\\x64\"",
        "\"" + wndkitPath + "\\10\\Lib\\10.0.10150.0\\ucrt\\x64\""
    };
    
    return borc::ToolChainCpp (
        info, 
        installPath, 
        compiler, 
        linker, 
        librarian, 
        compilerFlags, 
        linkerFlags, 
        includePaths, 
        libraryPaths        
    );
}

int main(int argc, char **argv) {
    namespace po = boost::program_options;
    
    try {
        // 
        po::options_description desc("Allowed options");
        
        desc.add_options()
            ("help,h", "Produce help message")
            ("build", "Generate all available build artifacts");
        
        po::variables_map vm;
        
        try {
            po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
            po::notify(vm);
            
            // handle help command
            if (vm.count("help")) {
                std::cout << desc << std::endl;
                
                return 0;
            } 
            
            // handle build command
            if (vm.count("build")) {
                auto project = createTestProject();
                //auto project = borc::Project::read("samples/ConsoleApp01/ConsoleApp01.yaml");
                
                auto toolchain = createToolChainGCC();
                //auto toolchain = createToolChainVC();
            
                try {
                    auto tasks = toolchain.generateBuildTasks(project);
            
                    for (auto &task : tasks) {
                        if (task) {
                            task->perform();
                        }
                    }
                    
                    return 0;
                } catch (const std::exception &exp) {
                    std::cout << exp.what() << std::endl;
                    return 1;
                }
            }
            
            // no option selected.
            throw po::error("No option selected.");
            
        } catch (const po::error &err) {
            std::cout << err.what() << std::endl;
            std::cout << desc << std::endl;
            
            return 100;
            
        } catch (const std::runtime_error &exp) {
            std::cout << exp.what() << std::endl;
            
            return 101;
        }
        
    } catch (const std::exception &exp) {
        std::cout << "borc command line tool unhandled exception:" << std::endl;
        std::cout << exp.what() << std::endl;
        
        return 1;
    }

    return 0;
}
