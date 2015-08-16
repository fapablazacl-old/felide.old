
#ifndef __felide_editor_editor_hpp__
#define __felide_editor_editor_hpp__

#include <string>
#include "felide/ProjectItem.hpp"

namespace felide { namespace editor {

    /**
     * @brief Generic source editor component interface.
     */
	class Editor {
	public:
        virtual ~Editor() {}

        virtual void setText(const std::string &text) {}
        virtual std::string getText() const {}

        virtual void setSavePoint() {}
        virtual void emptyUndoBuffer() {}
        virtual void clearAll() {}
        virtual void setTabWidth(const int spaces) {}

        virtual void setFont(const std::string &name, const int size) {}

        virtual ProjectItem* getProjectItem() {}
        virtual const ProjectItem* getProjectItem() const {}
	};
}}

#endif	// __felide_editor_editor_hpp__
