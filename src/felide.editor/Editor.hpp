
#ifndef __felide_editor_editor_hpp__
#define __felide_editor_editor_hpp__

#include <memory>
#include <string>
#include "felide/ProjectItem.hpp"

namespace felide { namespace editor {

    class Editor;
    typedef std::unique_ptr<Editor> EditorPtr;

    /**
     * @brief Generic source editor component interface.
     */
	class Editor {
	public:
        virtual ~Editor() {}

        virtual void setText(const std::string &text) = 0;
        virtual std::string getText() const = 0;

        virtual void setSavePoint() = 0;
        virtual void emptyUndoBuffer() = 0;
        virtual void clearAll() = 0;
        virtual void setTabWidth(const int spaces) = 0;

        virtual void setFont(const std::string &name, const int size) = 0;

        virtual ProjectItem* getProjectItem() = 0;
        virtual const ProjectItem* getProjectItem() const = 0;

		virtual void setTitle(const std::string &title) = 0;

		virtual int getId() const;
		virtual void setId(const int id);

	private:
		int id = 0;
		
    public:
        static Editor* new_(ProjectItemPtr item);
	};
}}

#endif	// __felide_editor_editor_hpp__
