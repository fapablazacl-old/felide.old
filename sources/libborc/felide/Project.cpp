//
//#include "Project.hpp"
//
//#include <map>
//#include <boost/filesystem/path.hpp>
////#include <yaml-cpp/yaml.h>
//
//namespace YAML {
//
//    static const std::map<std::string, borc::TargetType> typesMap = {
//        {"Executable", borc::TargetType::Executable}, 
//        {"Library", borc::TargetType::Library}
//    };
//
//
//    template<>
//    struct convert<borc::TargetType> {
//        static Node encode(const borc::Project &project) {
//            return Node();
//        }
//        
//        static bool decode(const Node &node, borc::TargetType &targetType) {
//            if (node.IsSequence() || node.IsNull()) {
//                return false;
//            }
//            
//            const auto key = node.as<std::string>();
//            
//            auto pair = typesMap.find(key);
//            
//            if (pair != typesMap.end()) {
//                targetType = pair->second;
//            } else {
//                targetType = borc::TargetType::Unknown;
//            }
//            
//            return true;
//        }
//    };
//    
//    template<>
//    struct convert<borc::Target> {
//        static Node encode(const borc::Project &project) {
//            return Node();
//        }
//                
//        static bool decode(const Node &node, borc::Target &target) {
//            if (!node.IsMap()) {
//                return false;
//            }
//            
//            target.name = node["name"].as<std::string>();
//            target.type = node["type"].as<borc::TargetType>();
//            
//            if (node["path"].IsDefined()) {
//                target.path = node["path"].as<std::string>();
//            } else {
//                target.path = ".";
//            }
//            
//            const auto includesNode = node["includes"];
//            
//            for (const auto &includeNode : includesNode) {
//                target.includes.push_back(includeNode.as<std::string>());
//            }
//            
//            const auto itemsNode = node["items"];
//            
//            for (const auto &itemNode : itemsNode) {
//                const auto item = borc::Item(itemNode.as<std::string>());
//                
//                target.items.push_back(item);
//            }
//            
//            return true;
//        }
//    };
//    
//    template<>
//    struct convert<borc::Project> {
//        static Node encode(const borc::Project &project) {
//            return Node();
//        }
//        
//        static bool decode(const Node &node, borc::Project &project) {
//            project.name = node["name"].as<std::string>();
//            
//            auto targetsNode = node["targets"];
//            
//            if (!targetsNode.IsDefined() || !targetsNode.IsSequence()) {
//                return false;
//            }
//            
//            for (const auto &targetNode : targetsNode) {
//                auto target = targetNode.as<borc::Target>();
//                project.targets.push_back(target);
//            }
//            
//            return true;
//        }
//    };
//}
//
//namespace fs = boost::filesystem;
//
//namespace borc {
//    Project Project::read(const std::string &file) {
//        YAML::Node projectYAML = YAML::LoadFile(file);
//        
//        Project project = projectYAML["project"].as<borc::Project>();
//        
//        project.path = fs::path(file).parent_path().string();
//        
//        return project;
//    }
//}
