
#include "SourceEditor.hpp"

#include <sstream>
#include <boost/filesystem.hpp>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qscilexercmake.h>

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
    
    SourceEditor::SourceEditor() 
    {
    }
    
    SourceEditor::SourceEditor(const QString &filePath) 
    {
        this->load(filePath);
    }
    
    QString SourceEditor::getTitle() const
    {
        std::stringstream ss;
        
        ss << (this->source.getDirtyFlag()?"[modified]":"");
        
        if (this->source.hasPath()) {
            ss << this->source.getPath() << " ";
        } else {
            ss << "Untitled " /*<< documentCount*/ << " ";
        }
        
        return QString(ss.str().c_str());
    }
    
    bool SourceEditor::getDirtyFlag() const
    {
        return this->source.getDirtyFlag();
    }
    
    void SourceEditor::save()
    {
        if (!this->source.hasPath()) {
            throw std::runtime_error("SourceEditor::save: Cannot save a file without a filename");
        }
        
        this->source.save(this->editorWidget->text().toStdString());
    }
    
    void SourceEditor::setLexer(QsciLexer *lexer)
    {
        if (lexer) {
            lexer->setDefaultFont(this->editorWidget->font());
        }
        
        this->editorWidget->setLexer(lexer);
    }
    
    void SourceEditor::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->editorWidget->text().toStdString();
        
        auto source = felide::model::Source(filename);
        source.save(content);
        
        this->source = source;
        this->setLexer(createLexer(filename));
    }
    
    void SourceEditor::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        
        auto source = felide::model::Source(filename);
        std::string content = source.load();
        source.setDirtyFlag(false);
        
        this->editorWidget->setText(QString(content.c_str()));
        this->source = source;
        this->setLexer(createLexer(filename));
    }
    
    void SourceEditor::undo()
    {
        this->editorWidget->undo();
    }
    
    void SourceEditor::redo()
    {
        this->editorWidget->redo();
        
    }
    
    void SourceEditor::copy()
    {
        this->editorWidget->copy();
    }
    
    void SourceEditor::cut()
    {
        this->editorWidget->cut();
    }
    
    void SourceEditor::paste()
    {
        this->editorWidget->paste();
    }
    
    QString SourceEditor::getFilePath() const
    {
        return QString(this->source.getPath().c_str());
    }
    
    bool SourceEditor::hasFilePath() const
    {
        return this->source.hasPath();
    }
}}
