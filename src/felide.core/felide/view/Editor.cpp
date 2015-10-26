
#include "Editor.hpp"

namespace felide { namespace editor {

	Editor::~Editor() {}

	int Editor::getId() const {
		return this->id;
	}

	void Editor::setId(const int id) {
		this->id = id;
	}
}}
