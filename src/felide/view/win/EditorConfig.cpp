//
//#include "EditorConfig.hpp"
//
//EditorConfig::EditorConfig() {
//
//	const char* cpp_keywords = {
//		"alignas alignof and and_eq asm atomic_cancel atomic_commit atomic_noexcept auto bitand bitor bool break case catch char "
//		"char16_t char32_t class compl concept const constexpr const_cast continue decltype default delete do "
//		"double dynamic_cast else enum explicit export extern false float for friend goto if inline int import long "
//		"module mutable namespace new noexcept not not_eq nullptr operator or or_eq private protected public "
//		"register reinterpret_cast requires return short signed sizeof static static_assert static_cast struct "
//		"switch synchronized template this thread_local "
//		"throw true try typedef typeid typename union unsigned "
//		"using virtual void volatile wchar_t while xor xor_eq"
//	};
//
//	std::map<int, COLORREF> cpp_colors = {
//		{SCE_C_COMMENT, RGB(0x00, 0x80, 0x00)}, 
//		{SCE_C_COMMENTLINE, RGB(0x00, 0x80, 0x00)}, 
//		{SCE_C_COMMENTDOC, RGB(0x00, 0x80, 0x00)}, 
//		{SCE_C_NUMBER, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_WORD, RGB(0x00, 0x00, 0xFF)}, 
//		{SCE_C_STRING, RGB(0x80, 0x00, 0x00)}, 
//		{SCE_C_CHARACTER, RGB(0x80, 0x00, 0x00)}, 
//		{SCE_C_UUID, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_PREPROCESSOR, RGB(0xA0, 0x00, 0xFF)}, 
//		{SCE_C_OPERATOR, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_IDENTIFIER, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_STRINGEOL, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_VERBATIM, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_REGEX, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_COMMENTLINEDOC, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_WORD2, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_COMMENTDOCKEYWORD, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_COMMENTDOCKEYWORDERROR, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_GLOBALCLASS, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_STRINGRAW, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_TRIPLEVERBATIM, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_HASHQUOTEDSTRING, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_PREPROCESSORCOMMENT, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_PREPROCESSORCOMMENTDOC, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_USERLITERAL, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_TASKMARKER, RGB(0x00, 0x00, 0x00)}, 
//		{SCE_C_ESCAPESEQUENCE, RGB(0x00, 0x00, 0x00)}
//	};
//
//	std::vector<wcl::ScintillaStyle> cpp_styles = {
//		{STYLE_DEFAULT, wcl::ScintillaColors::Black, wcl::ScintillaColors::White, 8, "Courier"},
//		{SCE_C_DEFAULT, wcl::ScintillaColors::Black, wcl::ScintillaColors::White, 8, "Courier"}
//	};
//
//	//m_textEditor.SetStyle(STYLE_DEFAULT, wcl::ScintillaColors::Black, wcl::ScintillaColors::White, 8, "Courier");
//	//m_textEditor.SendMessage_(SCI_SETLEXER, SCLEX_CPP);
//	//m_textEditor.SendMessage_(SCI_SETSTYLEBITS, 7);
//	//m_textEditor.SendMessage_(SCI_SETKEYWORDS, 0, (LPARAM)(cpp_keywords));
//
//	//m_textEditor.SetTabWidth(4);
//	//m_textEditor.SetStyle(SCE_C_DEFAULT, wcl::ScintillaColors::Black, wcl::ScintillaColors::White, 8, "Courier");
//
//	//for (auto style : cpp_colors) {
//	//	m_textEditor.SetStyle(style.first, style.second);
//
//	wcl::ScintillaConfig cppConfig;
//	cppConfig.lexer = SCLEX_CPP;
//	cppConfig.styleBits = 7;
//	cppConfig.keywords = cpp_keywords;
//	cppConfig.colors = cpp_colors;
//	cppConfig.styles = cpp_styles;
//
//	m_configurations[cppConfig.lexer] = cppConfig;
//}
//
//wcl::ScintillaConfig EditorConfig::getConfiguration(int lexer) {
//	return m_configurations[lexer];
//}
