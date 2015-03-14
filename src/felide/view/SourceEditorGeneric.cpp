
#include "SourceEditorGeneric.hpp"

#include <sstream>
#include <memory>
#include <boost/filesystem.hpp>


#include <QTextEdit>
#include <QGridLayout>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    namespace fs = boost::filesystem;
    
    static bool isExtensionCpp(const std::string &ext) 
    {
        return ext==".c" || ext==".h" || ext==".cpp" || ext==".hpp";
    }
    
    void SourceEditorGeneric::createWidget()
    {
        this->editorWidget = new QTextEdit(this);   
        
        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->editorWidget, 0, 0);
        
        this->setLayout(layout);
        this->show();
    }
    
    SourceEditorGeneric::SourceEditorGeneric(QWidget *parent) : SourceEditor(parent)
    {
        this->createWidget();
    }
    
    SourceEditorGeneric::SourceEditorGeneric(QWidget *parent, const QString &filePath)  : SourceEditor(parent)
    {
        this->createWidget();
        this->load(filePath);
    }
    
    QString SourceEditorGeneric::getTitle() const
    {
        std::stringstream ss;
        
        ss << (this->source.getDirtyFlag()?"[modified]":"");
        
        if (this->source.hasPath()) {
            ss << this->source.getPath() << " ";
        } else {
            ss << "Untitled " << SourceEditor::getDocumentCount() << " ";
        }
        
        return QString(ss.str().c_str());
    }
    
    void SourceEditorGeneric::save()
    {
        if (!this->source.hasPath()) {
            throw std::runtime_error("SourceEditorGeneric::save: Cannot save a file without a filename");
        }
		
        this->source.save(this->editorWidget->toPlainText().toStdString());
        
        // emit editorChanged(this->getTitle());
    }
    
    void SourceEditorGeneric::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->editorWidget->toPlainText().toStdString();
        
        auto source = felide::model::Source(filename);
        source.save(content);
        
        this->source = source;
        
        // emit editorChanged(this->getTitle());
    }
    
    void SourceEditorGeneric::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        
        auto source = felide::model::Source(filename);
        std::string content = source.load();
        source.setDirtyFlag(false);
        
        this->editorWidget->setText(QString(content.c_str()));
        this->source = source;
        
        // emit editorChanged(this->getTitle());
    }
    
    void SourceEditorGeneric::undo()
    {
        this->editorWidget->undo();
    }
    
    void SourceEditorGeneric::redo()
    {
        this->editorWidget->redo();
    }
    
    void SourceEditorGeneric::copy()
    {
        this->editorWidget->copy();
    }
    
    void SourceEditorGeneric::cut()
    {
        this->editorWidget->cut();
    }
    
    void SourceEditorGeneric::paste()
    {
        this->editorWidget->paste();
    }
    
    const felide::model::Source* SourceEditorGeneric::getSource() const 
    {
        return &this->source;
    }
    
    void SourceEditorGeneric::textChanged()
    {
        emit editorChanged(this->getTitle());
    }
}}
