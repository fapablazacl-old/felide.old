
#ifndef __felide_editor_view_hpp__
#define __felide_editor_view_hpp__

namespace felide { namespace editor {

	template<typename Controller>
	class View {
	public:
		virtual ~View() {}
		virtual void setHandler(Controller *handler) = 0;
		virtual Controller* getController() = 0;
		virtual const Controller* getController() const = 0;
	};

}}

#endif // __felide_editor_view_hpp__
