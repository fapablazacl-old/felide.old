
#include "Editor.hpp"

#if defined(FELIDE_GUI_TOOLKIT_WIN32XX)

namespace felide { namespace editor {
	int Editor::getId() const {
		return this->id;
	}

	void Editor::setId(const int id) {
		this->id = id;
	}
}}

#endif 
