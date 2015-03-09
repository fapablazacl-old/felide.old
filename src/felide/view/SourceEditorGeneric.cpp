
#include "SourceEditorGeneric.hpp"

#include <sstream>
#include <memory>
#include <boost/filesystem.hpp>

#include <QTextEdit>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
	struct SourceEditorGeneric::Impl 
	{
		QTextEdit *editorWidget = nullptr;
        felide::model::Source source;
	};
}}

namespace felide { namespace view {
    
    namespace fs = boost::filesystem;
    
    static bool isExtensionCpp(const std::string &ext) 
    {
        return ext==".c" || ext==".h" || ext==".cpp" || ext==".hpp";
    }
    
    SourceEditorGeneric::SourceEditorGeneric() 
    {
		this->impl = std::make_unique<SourceEditorGeneric::Impl>();
    }
    
    SourceEditorGeneric::SourceEditorGeneric(const QString &filePath) 
    {
		this->impl = std::make_unique<SourceEditorGeneric::Impl>();
        this->load(filePath);
    }
    
    QString SourceEditorGeneric::getTitle() const
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
    
    bool SourceEditorGeneric::getDirtyFlag() const
    {
        return this->impl->source.getDirtyFlag();
    }
    
    void SourceEditorGeneric::save()
    {
        if (!this->impl->source.hasPath()) {
            throw std::runtime_error("SourceEditorGeneric::save: Cannot save a file without a filename");
        }
		
        this->impl->source.save(this->impl->editorWidget->toPlainText().toStdString());
    }
    
    void SourceEditorGeneric::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->impl->editorWidget->toPlainText().toStdString();
        
        auto source = felide::model::Source(filename);
        source.save(content);
        
        this->impl->source = source;
    }
    
    void SourceEditorGeneric::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        
        auto source = felide::model::Source(filename);
        std::string content = source.load();
        source.setDirtyFlag(false);
        
        this->impl->editorWidget->setText(QString(content.c_str()));
        this->impl->source = source;
    }
    
    void SourceEditorGeneric::undo()
    {
        this->impl->editorWidget->undo();
    }
    
    void SourceEditorGeneric::redo()
    {
        this->impl->editorWidget->redo();
        
    }
    
    void SourceEditorGeneric::copy()
    {
        this->impl->editorWidget->copy();
    }
    
    void SourceEditorGeneric::cut()
    {
        this->impl->editorWidget->cut();
    }
    
    void SourceEditorGeneric::paste()
    {
        this->impl->editorWidget->paste();
    }
    
    QString SourceEditorGeneric::getFilePath() const
    {
        return QString(this->impl->source.getPath().c_str());
    }
    
    bool SourceEditorGeneric::hasFilePath() const
    {
        return this->impl->source.hasPath();
    }
}}
