
#include "felide.editor/qt5/QEditor.hpp"
#include "felide.editor/qt5/QTabbedEditor.hpp"
#include "felide.editor/qt5/QMainFrame.hpp"

#include <QGridLayout>
#include <QTabWidget>
#include <boost/filesystem/path.hpp>
#include <iostream>

namespace felide { namespace editor { namespace qt5 {
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
        assert(parent);
        assert(item);

        std::string lang = getLang(fs::path(item->getPath()).extension().string());

        QsciScintilla *editor = new QsciScintilla(parent);
        QsciLexer *lexer = selectLexer(editor, lang);

        applyLexer(editor, lexer);

        editor->setCaretLineVisible(true);

        return editor;
    }

    QEditor::QEditor(QWidget *parent, ProjectItemPtr item) : QWidget(parent) {
        this->item = std::move(item);
        this->scintilla = static_cast<QsciScintilla*>(createEditorWidget(this, this->item.get()));

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->scintilla);
        this->setLayout(layout);

        connect(this->scintilla, &QsciScintilla::textChanged, [this]() {
            throw std::runtime_error("");
                /*
            this->item->modify();

            auto mainFrame = static_cast<QMainFrame*>(this->tabbedEditor->parent());
            auto editor = static_cast<Editor*>(this);

            mainFrame->getHandler()->handleEditorChanged(editor);
            */
        });
    }

    QEditor::~QEditor() {}

    void QEditor::setText(const std::string &text) {
        this->scintilla->setText(text.c_str());
    }

    std::string QEditor::getText() const {
        return this->scintilla->text().toStdString();
    }

    void QEditor::setSavePoint(){
        // TODO:
    }

    void QEditor::emptyUndoBuffer() {
        // TODO:
    }

    void QEditor::clearAll() {
        this->scintilla->clear();
    }

    void QEditor::setTabWidth(const int spaces) {
        this->scintilla->setTabWidth(spaces);
    }

    void QEditor::setFont(const std::string &name, const int size) {
        QFont font = QFont(name.c_str(), size);

        if (scintilla->lexer()) {
            scintilla->lexer()->setDefaultFont(font);
            scintilla->lexer()->setFont(font);
        } else {
            scintilla->setFont(font);
        }
    }

    ProjectItem* QEditor::getProjectItem() {
        assert(this->item.get());

        return this->item.get();
    }

    const ProjectItem* QEditor::getProjectItem() const {
        assert(this->item.get());

        return this->item.get();
    }

    void QEditor::setTitle(const std::string &title) {
        assert(this->tabbedEditor);
        this->tabbedEditor->setEditorTitle(this, title.c_str());
    }

    void QEditor::undo() {
        assert(this->scintilla);
        this->scintilla->undo();
    }

    void QEditor::redo() {
        assert(this->scintilla);
        this->scintilla->redo();
    }

    void QEditor::cut() {
        assert(this->scintilla);
        this->scintilla->cut();
    }

    void QEditor::copy() {
        assert(this->scintilla);
        this->scintilla->copy();
    }

    void QEditor::paste() {
        assert(this->scintilla);
        this->scintilla->paste();
    }
}}}
