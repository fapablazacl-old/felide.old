#pragma once

#include <string>
#include <map>
#include <vector>
#include "felide/Config.hpp"
#include "felide/LexerConstants.hpp"

namespace felide {

	struct Color {
		uint8_t r=0, g=0, b=0, a=255;
		Color(uint8_t r_=0, uint8_t g_=0, uint8_t b_=0, uint8_t a_=255) : r(r_), g(g_), b(b_), a(a_) {}
	};

	/**
	 * @brief Information needed by the lexer for syntax coloring
	 */
	struct Lexer {
		//! The ID of the scintilla lexer.
		int name = 0;

		//! A list of keywords 
		std::vector<std::string> keywords;

		//! Token - Color map.
		std::map<int, Color> colors;
	};

	/**
	 * @brief Programming Language configuration. Holds all the information needed by the IDE to "know" the language.
	 */
	struct Language {

		//! The language name
		std::string name;	

		//! The hint shown in the file open/save dialog to describe the filter.	
		std::string filterHint;	

		//! A list of extensions, without dots, handled by the language.
		std::vector<std::string> extensions;	

		//! Information needed by the lexer for syntax coloring
		Lexer lexer;	

		/**
		 * @brief Build a filter string suitable for Windows API File Dialogs
		 */
		std::string buildFilter(const std::string &extSeparator, const char fieldSeparator) const;

		/**
		 * @brief Load the language configuration from the specified JSON file.
		 */
		static Language load(const std::string &file, const LexerConstants &constants);
	};

	/**
	 * IDE - wide configuration settings
	 */
	struct Config {
		std::vector<Language> languages;

		/** 
		 * @brief Build a filter suitable for Windows API File Dialogs
		 */
		std::string buildFilter(const char fieldSeparator) const;

		/**
		 * @brief Get the Language description data from the specified file path.
		 */
		const Language* findLanguage(const std::string &filepath) const;


		void load(const std::string &file, const LexerConstants &constants);
	};

    class App {
    public:
		App();
        virtual ~App();
        
        virtual int run(int argc, char **argv) = 0;

		Config* getConfig() {
			return &m_config;
		}

		const Config* getConfig() const {
			return &m_config;
		}

		std::string getTitle() const {
			return "wcl::IDE";
		}

	public:
		// implemented in the toolkit-specific implementation...
		static App* getInstance();

	private:
		Config m_config;
		LexerConstants m_constants;
    };
}
