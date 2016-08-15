
#include <cassert>
#include <iostream>
#include <string>

class Lexer;
class Language;
class BuildSystem;
class Workspace;
class Project;
class Item;
class Toolchain;

/**
 * @brief Collection interface.
 */
template<class T>
class Collection {
public:
    virtual ~Collection() {}
    virtual T get(const size_t index) = 0;
    virtual const T get(const size_t index) const = 0;
    virtual size_t count() const = 0;
};
//
//template<typename T>
//size_t begin(Collection<T> *col) {
//    assert(col);
//    return 0;
//}
//
//template<typename T>
//size_t end(Collection<T> *col) {
//    assert(col);
//    return col->count();
//}

template<class T>
class Dictionary {
public:
    virtual ~Dictionary() {}
    virtual Collection<std::string>* keys() = 0;
    virtual const Collection<std::string>* keys() const = 0;

    virtual T get(const std::string &key) = 0;
    virtual const T get(const std::string &key) const = 0;

    virtual size_t count() const {
        return this->keys()->count();
    }
};

//
//template<typename T>
//size_t begin(Dictionary<T> *dict) {
//    assert(dict);
//    return 0;
//}
//
//template<typename T>
//size_t end(Dictionary<T> *dict) {
//    assert(dict);
//    return col->count();
//}

class Core {
public:
    virtual ~Core() {}
};

class Lexer {
public:

};

class Language {
public:
    virtual ~Language() {}

    virtual bool compilable(const std::string &file) const = 0;

    virtual Collection<Toolchain*> *toolchains() = 0;

    virtual const Collection<Toolchain*> *toolchains() const = 0;
};

class BuildSystem {
public:
    virtual ~BuildSystem() {}

    virtual void build(Workspace *workspace, Toolchain *toolchain) = 0;
};

class Workspace {
public:
    virtual ~Workspace() {}

    virtual Collection<Project*>* projects() = 0;

    virtual const Collection<Project*>* projects() const = 0;
};

class Project {
public:
    virtual ~Project() {}

    virtual Collection<Project*>* dependencies() = 0;

    virtual const Collection<Project*>* dependencies() const = 0;
};

class Item {
public:
    virtual ~Item() {}

};

class Toolchain {
public:
    virtual ~Toolchain() {}

};

int main() {

    return 0;
}
