
#if 0

#include "SourceEditorScintilla.hpp"

#include <sstream>
#include <memory>
#include <boost/filesystem.hpp>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qscilexercmake.h>
#include <Qsci/qsciscintilla.h>

namespace felide { namespace view {
	struct SourceEditorScintilla::Impl 
	{
		QsciScintilla *editorWidget = nullptr;
        felide::model::Source source;

		void setLexer(QsciLexer *lexer) {
			if (lexer) {
				lexer->setDefaultFont(this->editorWidget->font());
			}
        
			this->editorWidget->setLexer(lexer);
		}
	};
}}

namespace felide { namespace view {
    
    namespace fs = boost::filesystem;
    
    static bool isExtensionCpp(const std::string &ext) 
    {
        return ext==".c" || ext==".h" || ext==".cpp" || ext==".hpp";
    }
    
    static QsciLexer* createLexer(const std::string &filename) 
    {
        QsciLexer *lexer = nullptr;
        
        // Select correct lexer type
        fs::path path = fs::path(filename);
        fs::path name = path.filename();
        
        if (isExtensionCpp(name.extension().string())) {
            QsciLexerCPP *cppLexer = new QsciLexerCPP();
            cppLexer->setFoldComments(true);
            
            lexer = cppLexer;
        }
        
        if (name.string() == "CMakeLists.txt") {
            lexer = new QsciLexerCMake();
        }
        
        return lexer;
    }
    
    SourceEditorScintilla::SourceEditorScintilla() 
    {
		this->impl = std::make_unique<SourceEditorScintilla::Impl>();
    }
    
    SourceEditorScintilla::SourceEditorScintilla(const QString &filePath) 
    {
		this->impl = std::make_unique<SourceEditorScintilla::Impl>();
        this->load(filePath);
    }
    
	void SourceEditorScintilla::initializeEditor() 
	{
		// font
		QFont font("Monospace", 8);
		font.setFixedPitch(true);
        
		this->impl->editorWidget->setFont(font);
        
		// margins
		QFontMetrics fontmetrics = QFontMetrics(font);
		this->impl->editorWidget->setMarginsFont(font);
		this->impl->editorWidget->setMarginWidth(0, fontmetrics.width(QString::number(this->impl->editorWidget->lines())) + 6);
		this->impl->editorWidget->setMarginLineNumbers(0, true);
		this->impl->editorWidget->setMarginsBackgroundColor(QColor("#cccccc"));
    
		connect(this->impl->editorWidget, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
        
		// caret
		this->impl->editorWidget->setCaretLineVisible(true);
		this->impl->editorWidget->setCaretLineBackgroundColor(QColor("#ffe4e4"));
        
		// initialize folding
		QsciScintilla::FoldStyle state = static_cast<QsciScintilla::FoldStyle>((!this->impl->editorWidget->folding()) * 5);
        
		if (!state) {
			this->impl->editorWidget->foldAll(false);
		}
        
		this->impl->editorWidget->setFolding(state);
        
		// initialize tabulation
		this->impl->editorWidget->setIndentationsUseTabs(false);
		this->impl->editorWidget->setIndentationWidth(4);
		this->impl->editorWidget->setAutoIndent(true);
	}

    QString SourceEditorScintilla::getTitle() const
    {
        std::stringstream ss;
        
        ss << (this->impl->source.getDirtyFlag()?"[modified]":"");
        
        if (this->impl->source.hasPath()) {
            ss << this->impl->source.getPath() << " ";
        } else {
            ss << "Untitled " /*<< documentCount*/ << " ";
        }
        
        return QString(ss.str().c_str());
    }
    
    bool SourceEditorScintilla::getDirtyFlag() const
    {
        return this->impl->source.getDirtyFlag();
    }
    
    void SourceEditorScintilla::save()
    {
        if (!this->impl->source.hasPath()) {
            throw std::runtime_error("SourceEditorScintilla::save: Cannot save a file without a filename");
        }
        
        this->impl->source.save(this->impl->editorWidget->text().toStdString());
    }
    
    void SourceEditorScintilla::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->impl->editorWidget->text().toStdString();
        
        auto source = felide::model::Source(filename);
        source.save(content);
        
        this->impl->source = source;
        this->impl->setLexer(createLexer(filename));
    }
    
    void SourceEditorScintilla::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        
        auto source = felide::model::Source(filename);
        std::string content = source.load();
        source.setDirtyFlag(false);
        
        this->impl->editorWidget->setText(QString(content.c_str()));
        this->impl->source = source;
        this->impl->setLexer(createLexer(filename));
    }
    
    void SourceEditorScintilla::undo()
    {
        this->impl->editorWidget->undo();
    }
    
    void SourceEditorScintilla::redo()
    {
        this->impl->editorWidget->redo();
        
    }
    
    void SourceEditorScintilla::copy()
    {
        this->impl->editorWidget->copy();
    }
    
    void SourceEditorScintilla::cut()
    {
        this->impl->editorWidget->cut();
    }
    
    void SourceEditorScintilla::paste()
    {
        this->impl->editorWidget->paste();
    }
    
    QString SourceEditorScintilla::getFilePath() const
    {
        return QString(this->impl->source.getPath().c_str());
    }
    
    bool SourceEditorScintilla::hasFilePath() const
    {
        return this->impl->source.hasPath();
    }
}}

#endif
