
#include "Editor.hpp"

namespace felide { namespace view {

	Editor::~Editor() {}

	int Editor::getId() const {
		return this->id;
	}

	void Editor::setId(const int id) {
		this->id = id;
	}
}}
