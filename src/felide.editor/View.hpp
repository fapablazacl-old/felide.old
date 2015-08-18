
#ifndef __felide_editor_view_hpp__
#define __felide_editor_view_hpp__

#include "DialogFactory.hpp"

namespace felide { namespace editor {

	template<typename Handler>
	class View {
	public:
		View(DialogFactory *dialogFactory);
		virtual ~View() {}
		virtual void setHandler(Handler *handler) = 0;
		virtual Handler* getHandler() = 0;
		virtual const Handler* getHandler() const = 0;

		virtual DialogFactory* getDialogFactory() const;

	private:
		DialogFactory *dialogFactory = nullptr;
	};

	template<typename Handler>
	inline View<Handler>::View(DialogFactory *dialogFactory) {
		this->dialogFactory = dialogFactory;
	}

	template<typename Handler>
	inline DialogFactory* View<Handler>::getDialogFactory() const {
		return this->dialogFactory;
	}
}}

#endif // __felide_editor_view_hpp__
