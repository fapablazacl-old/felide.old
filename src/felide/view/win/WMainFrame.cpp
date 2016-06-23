
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

#include "WEditor.hpp"

namespace fs = boost::filesystem;

namespace felide { namespace view { namespace win {

	WMainFrame::WMainFrame(WAppImpl *app) : Frame(L"MainFrame"), MainFrame(app->getDialogFactory()), m_app(app) {}

	//static wcl::ScintillaConfig GetScintillaConfig(const Lexer &lexer) {
	//	wcl::ScintillaConfig config;

	//	config.lexer = lexer.name;
	//	
	//	for (const auto &pair : lexer.colors) {
	//		const auto color = pair.second;
	//		config.colors[pair.first] = RGB(color.r, color.g, color.b);
	//	}

	//	config.keywords = boost::join(lexer.keywords, " ");

	//	return config;
	//}

	//static std::string LoadTextFile(const std::string &file) {
	//
	//	std::fstream fs;
	//	fs.open(file.c_str(), std::ios_base::in);

	//	if (!fs.is_open()) {
	//		throw std::runtime_error("Can't load file '" + file + "'");
	//	}

	//	std::string text;

	//	while (!fs.eof()) {
	//		std::string line;
	//		std::getline(fs, line);

	//		text += line + "\n";
	//	}

	//	return text;
	//}

	//static std::string SaveTextFile(const std::string &file, const std::string &content) {
	//	std::fstream fs;
	//	fs.open(file.c_str(), std::ios_base::out);
	//
	//	if (!fs.is_open()) {
	//		throw std::runtime_error("Can't save file '" + file + "'");
	//	}

	//	fs << content << std::endl;
	//}


	void WMainFrame::OnClose() {
		this->PostMessage_(WM_QUIT);
	}

	void WMainFrame::OnFileExit() {
		this->PostMessage_(WM_QUIT);
	}

	void WMainFrame::OnCommand(const int commandId) {

		switch (commandId) {
		case ID_FILE_NEW: m_handler.handleFileNew(); break;
		case ID_FILE_OPEN: m_handler.handleFileOpen(); break;
		case ID_FILE_SAVE: m_handler.handleFileSave(); break;
		case ID_FILE_SAVEAS: m_handler.handleFileSaveAs(); break;
		case ID_FILE_SAVEALL: m_handler.handleFileSaveAll(); break;
		case ID_FILE_CLOSE: m_handler.handleFileCloseAll(); break;
		case ID_FILE_CLOSEALL: m_handler.handleFileClose(); break;
		case ID_FILE_EXIT: m_handler.handleFileExit(); break;
		}

		//if (commandId == ID_FILE_EXIT) {
		//	this->OnFileExit();

		//} else if (commandId == ID_FILE_NEW) {
		//	m_handler.handleFileNew();

		//} else if (commandId == ID_FILE_OPEN) {
		//	m_handler.handleFileOpen();

		//	//const std::string filter = m_app->getConfig()->buildFilter('|');
		//	//const std::wstring wfilter(filter.begin(), filter.end());

		//	//wcl::FileDialog fileDialog(L"Open File", wfilter);

		//	//fileDialog.ShowOpen();

		//	//if (!fileDialog.UserCancel()) {
		//	//	const std::wstring wfilepath = fileDialog.GetFileName();

		//	//	const std::string filepath(wfilepath.begin(), wfilepath.end());
		//	//	const std::string filetext = LoadTextFile(filepath);

		//	//	const Language *lang = m_app->getConfig()->findLanguage(filepath);
		//	//
		//	//	m_textEditor.SetText(filetext);

		//	//	if (lang) {
		//	//		const wcl::ScintillaConfig config = GetScintillaConfig(lang->lexer);
		//	//		m_textEditor.ApplyConfig(config);

		//	//	} else {
		//	//		this->SendMessage_(SCI_SETLEXER, SCLEX_NULL);
		//	//	}
		//	//}
		//} else if (commandId == ID_FILE_SAVE) {
		//	m_handler.handleFileSave();

		//}
	}

	void WMainFrame::OnSize(const int width, const int height) {
		m_sizer.OnSize(width, height);
	}


	Editor* WMainFrame::createEditor(ProjectItemPtr item) {
		auto weditor = std::make_unique<WEditor>(std::move(item));

		weditor->Create(L"", WS_CHILD | WS_VISIBLE, 0, 0, 10, 10, this->GetHandle());

		auto editor = weditor.get();
		auto name = weditor->getProjectItem()->getName();

		m_tabbedPanel.AppendTab(std::wstring(name.begin(), name.end()), std::move(weditor));

		return editor;
	}

	void WMainFrame::closeEditor(Editor* view) {
		std::cout << "WMainFrame::closeEditor: Not implemented." << std::endl;
	}

	Editor* WMainFrame::getCurrentEditor() {
		return dynamic_cast<Editor*>(m_tabbedPanel.GetCurrentTab()->GetWindow());
	}

	const Editor* WMainFrame::getCurrentEditor() const {
		return dynamic_cast<const Editor*>(m_tabbedPanel.GetCurrentTab()->GetWindow());
	}

	int WMainFrame::getEditorCount() const {
		return m_tabbedPanel.GetTabCount();
	}

	Editor* WMainFrame::getEditor(const int index) {
		return dynamic_cast<Editor*>(m_tabbedPanel.GetTab(index)->GetWindow());
	}

	const Editor* WMainFrame::getEditor(const int index) const {
		return dynamic_cast<const Editor*>(m_tabbedPanel.GetTab(index)->GetWindow());
	}
		
	void WMainFrame::setEditorTitle(Editor *view, const std::string &title) {
		auto window = dynamic_cast<const wcl::Window*>(view);
		m_tabbedPanel.GetTab(window)->SetText(std::wstring(title.begin(), title.end()));
	}

	std::string WMainFrame::getEditorTitle(Editor *view) const {
		auto window = dynamic_cast<const wcl::Window*>(view);
		auto wtitle = m_tabbedPanel.GetTab(window)->GetText();

		return std::string(wtitle.begin(), wtitle.end());
	}
		
	void WMainFrame::close() {
		this->Close();
	}

	void WMainFrame::updateEnableStatus() {

	}
}}}
