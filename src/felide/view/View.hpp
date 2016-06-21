
#ifndef __felide_editor_view_hpp__
#define __felide_editor_view_hpp__

#include <memory>

#include "DialogFactory.hpp"

namespace felide { namespace view {
    
	template<typename Handler>
	class View {
	public:
		explicit View(DialogFactory *dialogFactory) : m_dialogFactory(dialogFactory) {}
		
		virtual ~View() {}
        
		DialogFactory* getDialogFactory() const {
			return m_dialogFactory;
		}
        
	protected:
		DialogFactory *m_dialogFactory = nullptr;
        Handler m_handler;
	};
}}

#endif 
