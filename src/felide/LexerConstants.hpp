#pragma once

#include <string>
#include <map>

namespace felide {
	class LexerConstants {
	public:
		LexerConstants () {}
		~LexerConstants () {}

		void load(const std::string &file);

		int getConstant(const std::string &constantName) const;

	private:
		std::map<std::string, int> m_constants;
	};
}
