
#ifndef __FELIDE_MODEL_PROJECTITEM_HPP__
#define __FELIDE_MODEL_PROJECTITEM_HPP__

#include <string>
#include <boost/signals2.hpp>

namespace felide { namespace model {
    class ProjectItem {
    public:
        //! Fired when the modification flag of ProjectItem changes.
        boost::signals2::signal<void()> modifyChanged;
        
    public:
        ProjectItem();
        
        explicit ProjectItem(const std::string &path);
        
        ~ProjectItem();
        
        //! Sets the modification flag to 'true'
        void modify();
        
        //! Get the current modification flag
        bool isModified() const;
        
        //! Open the current file. Throws a std::runtime_error exception if the ProjectItem has no file associated.
        std::string open();
        
        //! Open the specified file.
        std::string open(const std::string &filename);
        
        void save(const std::string &content);
        void save(const std::string &content, const std::string &filename);
        
        bool hasPath() const;
        void setPath(const std::string &path);

        std::string getPath() const;
        
        std::string getName() const;
        
        void new_();
        
    protected:
        /**
         * @brief Sets the new modified status and trigger the modifyChanged signal
         */
        void modifyAndTrigger(bool modified);
        
    private:
        std::string path;
        bool modified = false;
    };
}}

#endif	// __FELIDE_MODEL_PROJECTITEM_HPP__
