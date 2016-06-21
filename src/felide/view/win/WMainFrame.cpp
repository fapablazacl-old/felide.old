
#include "WMainFrame.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <wcl/FileDialog.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/range/algorithm.hpp>

namespace fs = boost::filesystem;

namespace felide { namespace view { namespace win {

	WMainFrame::WMainFrame(AppImpl *app) : Frame(L"MainFrame"), m_app(app) {}

	static wcl::ScintillaConfig GetScintillaConfig(const Lexer &lexer) {
		wcl::ScintillaConfig config;

		config.lexer = lexer.name;
		
		for (const auto &pair : lexer.colors) {
			const auto color = pair.second;
			config.colors[pair.first] = RGB(color.r, color.g, color.b);
		}

		config.keywords = boost::join(lexer.keywords, " ");

		return config;
	}

	static std::string LoadTextFile(const std::string &file) {
	
		std::fstream fs;
		fs.open(file.c_str(), std::ios_base::in);

		if (!fs.is_open()) {
			throw std::runtime_error("Can't load file '" + file + "'");
		}

		std::string text;

		while (!fs.eof()) {
			std::string line;
			std::getline(fs, line);

			text += line + "\n";
		}

		return text;
	}

	static std::string SaveTextFile(const std::string &file, const std::string &content) {
		std::fstream fs;
		fs.open(file.c_str(), std::ios_base::out);
	
		if (!fs.is_open()) {
			throw std::runtime_error("Can't save file '" + file + "'");
		}

		fs << content << std::endl;
	}

	void WMainFrame::SetFile(const std::string &filename, const std::string &content) {
		m_filename = filename;
		m_textEditor.SetText(content);
	}

	void WMainFrame::OnClose() {
		this->PostMessage_(WM_QUIT);
	}

	void WMainFrame::OnFileExit() {
		this->PostMessage_(WM_QUIT);
	}

	void WMainFrame::OnCommand(const int commandId) {

		if (commandId == ID_FILE_EXIT) {
			this->OnFileExit();

		} else if (commandId == ID_FILE_NEW) {
		

		} else if (commandId == ID_FILE_OPEN) {
			const std::string filter = m_app->getConfig()->buildFilter('|');
			const std::wstring wfilter(filter.begin(), filter.end());

			wcl::FileDialog fileDialog(L"Open File", wfilter);

			fileDialog.ShowOpen();

			if (!fileDialog.UserCancel()) {
				const std::wstring wfilepath = fileDialog.GetFileName();

				const std::string filepath(wfilepath.begin(), wfilepath.end());
				const std::string filetext = LoadTextFile(filepath);

				const Language *lang = m_app->getConfig()->findLanguage(filepath);
			
				m_textEditor.SetText(filetext);

				if (lang) {
					const wcl::ScintillaConfig config = GetScintillaConfig(lang->lexer);
					m_textEditor.ApplyConfig(config);

				} else {
					this->SendMessage_(SCI_SETLEXER, SCLEX_NULL);
				}
			}
		} else if (commandId == ID_FILE_SAVE) {

		}
	}

	void WMainFrame::OnSize(const int width, const int height) {
		m_sizer.OnSize(width, height);
	}
}}}