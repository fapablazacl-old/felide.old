
#include "TabbedEditor.hpp"
#include <QGridLayout>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

#include <boost/filesystem/path.hpp>

namespace felide { namespace qt5 {
    
    namespace fs = boost::filesystem;

    TabbedEditor::TabbedEditor(QWidget *parent) : QWidget(parent) {
        this->tabWidget = new QTabWidget(this);
        this->tabWidget->setTabsClosable(true);
        
        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget);
        this->setLayout(layout);
    }
    
    std::string getLang(const std::string &ext) {
        std::string lang = "";
        
        if (ext==".hpp" || ext==".cpp") {
            lang = "c++";
        }
        
        return lang;
    }
    
    QWidget* createEditor(QWidget *parent, ProjectItem *item) {
        std::string lang = getLang(fs::path(item->getPath()).extension().string());
        
        QsciScintilla *editor = new QsciScintilla(parent);
        
        QsciLexer *lexer = nullptr;
        if (lang == "c++") {
            lexer = new QsciLexerCPP(editor);
        }
        
        if (lexer) {
            lexer->setDefaultFont(QFont("Inconsolata"));
            editor->setLexer(lexer);
        }
        
        return editor;
    }
    
    void TabbedEditor::openEditor(ProjectItem *item) {
        this->tabWidget->addTab(createEditor(this->tabWidget, item), "Test01");
    }
}}
