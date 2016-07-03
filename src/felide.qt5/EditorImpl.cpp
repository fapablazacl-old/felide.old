
#include "EditorImpl.hpp"
#include "TabbedEditor.hpp"
#include "MainFrameImpl.hpp"

#include <QGridLayout>
#include <QTabWidget>
#include <boost/filesystem/path.hpp>
#include <iostream>

namespace felide { namespace view { namespace qt5 {
    namespace fs = boost::filesystem;

    static std::string getLang(const std::string &ext) {
        std::string lang = "";

        if (ext==".hpp" || ext==".cpp") {
            lang = "c++";
        }

        return lang;
    }

    static QsciLexer* selectLexer(QWidget *view, const std::string &lang) {
        QsciLexer *lexer = nullptr;

        if (lang == "c++") {
            lexer = new QsciLexerCPP(view);
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

        QsciScintilla *view = new QsciScintilla(parent);
        QsciLexer *lexer = selectLexer(view, lang);

        applyLexer(view, lexer);

        view->setCaretLineVisible(true);
        
        return view;
    }

    EditorImpl::EditorImpl(QWidget *parent, ProjectItemPtr item) : QWidget(parent) {
        m_item = std::move(item);
        m_scintilla = static_cast<QsciScintilla*>(createEditorWidget(this, m_item.get()));

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(m_scintilla);
        this->setLayout(layout);
        
        connect(m_scintilla, &QsciScintilla::textChanged, [this]() {
            m_item->setModifyFlag(true);
            
            auto mainFrame = static_cast<MainFrameImpl*>(m_tabbedEditor->parent());
            auto view = static_cast<EditorImpl*>(this);
        });
    }

    EditorImpl::~EditorImpl() {}

    void EditorImpl::setText(const std::string &text) {
        m_scintilla->setText(text.c_str());
    }

    std::string EditorImpl::getText() const {
        return m_scintilla->text().toStdString();
    }

    void EditorImpl::setSavePoint(){
        // TODO:
    }

    void EditorImpl::emptyUndoBuffer() {
        // TODO:
    }

    void EditorImpl::clearAll() {
        m_scintilla->clear();
    }

    void EditorImpl::setTabWidth(const int spaces) {
        m_scintilla->setTabWidth(spaces);
    }

    void EditorImpl::setFont(const std::string &name, const int size) {
        QFont font = QFont(name.c_str(), size);

        if (m_scintilla->lexer()) {
            m_scintilla->lexer()->setDefaultFont(font);
            m_scintilla->lexer()->setFont(font);
        } else {
            m_scintilla->setFont(font);
        }
    }

    ProjectItem* EditorImpl::getProjectItem() {
        assert(m_item.get());

        return m_item.get();
    }

    const ProjectItem* EditorImpl::getProjectItem() const {
        assert(m_item.get());

        return m_item.get();
    }

    void EditorImpl::setTitle(const std::string &title) {
        assert(m_tabbedEditor);
        m_tabbedEditor->setEditorTitle(this, title.c_str());
    }

    void EditorImpl::undo() {
        assert(m_scintilla);
        m_scintilla->undo();
    }

    void EditorImpl::redo() {
        assert(m_scintilla);
        m_scintilla->redo();
    }

    void EditorImpl::cut() {
        assert(m_scintilla);
        m_scintilla->cut();
    }

    void EditorImpl::copy() {
        assert(m_scintilla);
        m_scintilla->copy();
    }

    void EditorImpl::paste() {
        assert(m_scintilla);
        m_scintilla->paste();
    }
    
    void EditorImpl::setFocus() {
        assert(m_scintilla);
        
        m_scintilla->setFocus();
    }
}}}
