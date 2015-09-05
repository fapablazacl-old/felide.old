
#ifndef __felide_editor_view_hpp__
#define __felide_editor_view_hpp__

#include <memory>
#include "DialogFactory.hpp"

namespace felide { namespace editor {
    
	template<typename Handler>
	class View {
    public:
        typedef std::unique_ptr<Handler> HandlerPtr;
    
	public:
		View(DialogFactory *dialogFactory);
		virtual ~View() {}
        
		DialogFactory* getDialogFactory() const;

        void setHandler(HandlerPtr handler);
		Handler* getHandler();
		const Handler* getHandler() const;
        
	private:
		DialogFactory *dialogFactory = nullptr;
        HandlerPtr handler;
	};

	template<typename Handler>
	inline View<Handler>::View(DialogFactory *dialogFactory) {
		this->dialogFactory = dialogFactory;
	}

	template<typename Handler>
	inline DialogFactory* View<Handler>::getDialogFactory() const {
		return this->dialogFactory;
	}
    
    template<typename Handler>
    void View<Handler>::setHandler(typename View<Handler>::HandlerPtr handler) {
        this->handler = std::move(handler);
    }
    
    template<typename Handler>
    Handler* View<Handler>::getHandler() {
        return this->handler.get();
    }
    
    template<typename Handler>
    const Handler* View<Handler>::getHandler() const {
        return this->handler.get();
    }
}}

#endif // __felide_editor_view_hpp__
