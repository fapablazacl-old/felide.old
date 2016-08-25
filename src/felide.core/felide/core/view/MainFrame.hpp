
#ifndef __felide_core_view_mainframe_hpp__
#define __felide_core_view_mainframe_hpp__

#include <cstddef>
#include <felide/core/PreDef.hpp>

namespace felide { namespace core { namespace view {

    class FELIDE_CORE_API Editor;
    class FELIDE_CORE_API MainFrame {
    public:
        virtual ~MainFrame();
        
        virtual std::size_t getEditorCount() const = 0;
        virtual Editor* getEditor(const std::size_t index) = 0;
        virtual const Editor* getEditor(const std::size_t index) const = 0;

        virtual Editor* appendEditor();
        virtual Editor* appendEditor(const std::size_t pos) = 0;
    };
}}}

#endif 
