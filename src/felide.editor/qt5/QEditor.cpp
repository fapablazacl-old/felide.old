
#include "felide.editor/qt5/QEditor.hpp"

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

    QEditor::QEditor(QWidget *parent, ProjectItem *item) : QWidget(parent) {
        this->item = item;
        this->scintilla = static_cast<QsciScintilla*>(createEditorWidget(this, item));

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->scintilla);
        this->setLayout(layout);

        this->open();

        connect(this->scintilla, &QsciScintilla::textChanged, [this]() {
            this->item->modify();
            this->titleUpdated(this);
        });
    }

    void QEditor::open() {
        if (item->hasPath()) {
            QString text = QString::fromStdString(item->open());
            this->scintilla->setText(text);
        }

        this->titleUpdated(this);
    }

    void QEditor::save() {
        QString text = this->scintilla->text();
        this->item->save(text.toStdString());

        this->titleUpdated(this);
    }

    void QEditor::save(QString path) {
        QString text = this->scintilla->text();
        this->item->save(text.toStdString(), path.toStdString());

        this->titleUpdated(this);
    }

    void QEditor::onUndo() {
        this->scintilla->undo();
    }

    void QEditor::onRedo() {
        this->scintilla->redo();
    }

    void QEditor::onCut() {
        this->scintilla->cut();
    }

    void QEditor::onCopy() {
        this->scintilla->copy();
    }

    void QEditor::onPaste() {
        this->scintilla->paste();
    }

    QEditor::~QEditor() {}
    
    void QEditor::setText(const std::string &text) {
        
    }
    
    std::string QEditor::getText() const {
        return "";
    }

    void QEditor::setSavePoint(){
        
    }
    void QEditor::emptyUndoBuffer() {
        
    }
    void QEditor::clearAll() {
        
    }
    void QEditor::setTabWidth(const int spaces) {
        
    }

    void QEditor::setFont(const std::string &name, const int size) {
        
    }

    ProjectItem* QEditor::getProjectItem() {
        return nullptr;
    }
    
    const ProjectItem* QEditor::getProjectItem() const {
        return nullptr;
    }

    void QEditor::setTitle(const std::string &title) {
        
    }
}}
