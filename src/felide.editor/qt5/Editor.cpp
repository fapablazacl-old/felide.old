
#include "Editor.hpp"

#include <QGridLayout>
#include <boost/filesystem/path.hpp>

namespace felide { namespace qt5 {
    namespace fs = boost::filesystem;
    
    static std::string getLang(const std::string &ext) {
        std::string lang = "";
        
        if (ext==".hpp" || ext==".cpp") {
            lang = "c++";
        }
        
        return lang;
    }
    
    static QsciLexer* selectLexer(QWidget *editor, const std::string &lang) {
        QsciLexer *lexer = nullptr;
        
        if (lang == "c++") {
            lexer = new QsciLexerCPP(editor);
        }
        
        return lexer;
    }
    
    static void applyLexer(QsciScintilla *scintilla, QsciLexer *lexer) {
        QFont font = QFont("Inconsolata", 10);
        
        if (lexer) {
            lexer->setDefaultFont(font);
            lexer->setFont(font);
            scintilla->setLexer(lexer);
        } else {
            scintilla->setFont(font);
        }
    }
    
    static QWidget* createEditorWidget(QWidget *parent, ProjectItem *item) {
        std::string lang = getLang(fs::path(item->getPath()).extension().string());
        
        QsciScintilla *editor = new QsciScintilla(parent);
        QsciLexer *lexer = selectLexer(editor, lang);
        
        applyLexer(editor, lexer);
        
        editor->setCaretLineVisible(true);
        
        return editor;
    }
    
    Editor::Editor(QWidget *parent, ProjectItem *item) : QWidget(parent) {
        this->item = item;
        this->scintilla = static_cast<QsciScintilla*>(createEditorWidget(this, item));
        
        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->scintilla);
        this->setLayout(layout);
        
        this->open();
    }

    void Editor::open() {
        if (item->hasPath()) {
            QString text = QString::fromStdString(item->open());
            this->scintilla->setText(text);
        }
        
        this->titleUpdated(this);
    }
    
    void Editor::save() {
        QString text = this->scintilla->text();
        this->item->save(text.toStdString());
        
        this->titleUpdated(this);
    }
    
    void Editor::save(QString path) {
        QString text = this->scintilla->text();
        this->item->save(text.toStdString(), path.toStdString());
        
        this->titleUpdated(this);
    }
    
    Editor::~Editor() {}
}}
