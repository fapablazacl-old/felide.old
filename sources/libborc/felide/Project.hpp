
#pragma once

#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Version.hpp"

namespace borc {
    /**
     * @brief Processor architecture
     */
    enum class Arch {
        Unknown,
        Host,
        x86,
        x86_64
    };

    enum class Endianess {
        Unknown,
        Little,
        Big
    };

    enum class AddressModel {
        Unknown,
        Am32,
        Am64
    };

    inline Arch getHostArch() {
        return Arch::x86_64;
    }

    inline Endianess getEndianess(const Arch arch) {
        switch (arch) {
        case Arch::Host: return getEndianess(getHostArch());
        case Arch::x86: case Arch::x86_64: return Endianess::Little;
        default: return Endianess::Unknown;
        }
    }

    inline AddressModel getAddressModel(const Arch arch) {
        switch (arch) {
        case Arch::Host: return getAddressModel(getHostArch());
        case Arch::x86: return AddressModel::Am32;
        case Arch::x86_64: return AddressModel::Am64;
        default: return AddressModel::Unknown;
        }
    }

    enum class TargetType {
        Unknown, 
        Executable,
        Library
    };

    enum class LinkType {
        Unknown,
        Static,
        Dynamic
    };

    enum class ThreadingType {
        Unknown,
        Single,
        Multi
    };

    enum class BuildType {
        Unknown,
        Debug,
        Release
    };

    struct Item {
        std::string file;

        Item() {}

        Item(const std::string &file_) : file(file_) {}
    };

    struct Depedency {
        std::string name;
    };

    struct Target {
        std::string name;
        std::string path;
        std::vector<Depedency> dependencies;
        TargetType type = TargetType::Unknown;
        std::vector<Item> items;
        std::vector<std::string> includes;
        
        Target() {}

        Target(const std::string &name_, const std::string &path_, const TargetType type_) 
            : name(name_), path(path_), type(type_) {}

        Target(const std::string &name_, const std::string &path_, const TargetType type_, const std::vector<Item> &items_) 
            : name(name_), path(path_), type(type_), items(items_) {}

        Target(const std::string &name_, const std::string &path_, const TargetType type_, const std::vector<Item> &items_, const std::string &include) 
            : name(name_), path(path_), type(type_), items(items_), includes({include}) {}

        Target(const std::string &name_, const std::string &path_, const TargetType type_, const std::vector<Item> &items_, const std::vector<std::string> &includes_) 
            : name(name_), path(path_), type(type_), items(items_), includes(includes_) {}
    };

    struct Project {
    public:
        std::string name;
        std::string path;
        std::vector<Target> targets;
        std::vector<std::string> includes;  // include directories (C++ specific)

        Project() {}

        Project(const std::string &name_, const std::string &path_) 
            : name(name_), path(path_) {}

        Project(const std::string &name_, const std::string &path_, const Target &target_) 
            : name(name_), path(path_), targets({target_}) {}

        Project(const std::string &name_, const std::string &path_, const std::vector<Target> &targets_) 
            : name(name_), path(path_), targets(targets_) {}
      
    public:
        //static Project read(const std::string &file);
    };

    struct Configuration {
        std::string name;

        LinkType link = LinkType::Unknown;
        ThreadingType threading = ThreadingType::Unknown;
        BuildType build = BuildType::Unknown;
    };
}

#endif 
