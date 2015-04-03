
#include "SourceEditorGeneric.hpp"

#include <sstream>
#include <memory>
#include <boost/filesystem.hpp>

#include <QTextEdit>
#include <QGridLayout>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    using namespace felide::model;

    namespace fs = boost::filesystem;
    
    void SourceEditorGeneric::createWidget()
    {
        this->projectItem = new ProjectItem();
        
        this->editorWidget = new QTextEdit(this);
        QObject::connect(this->editorWidget, &QTextEdit::textChanged, [this]() {
            this->projectItem->modify();
            emit sourceChanged(this);
        });
        
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
    
    SourceEditorGeneric::~SourceEditorGeneric()
    {
        boost::checked_delete(this->projectItem);
    }
    
    QString SourceEditorGeneric::getFileTitle() const
    {
        std::string fileTitle;
        
        if (this->getProjectItem()->hasPath()) {
            fileTitle = this->getProjectItem()->getName();
        } else {
            fileTitle = "Untitled " + std::to_string(this->getEditorNumber());
        }
        
        return QString::fromStdString(fileTitle);
    }
    
    QString SourceEditorGeneric::getTitle() const
    {
        std::stringstream ss;
        
        ss << (this->getProjectItem()->isModified()?"[*] ":"");
        ss << this->getFileTitle().toStdString() << " ";
        
        return QString::fromStdString(ss.str());
    }
    
    void SourceEditorGeneric::new_() 
    {
        this->editorWidget->setText("");
        this->getProjectItem()->new_();   
    }
    
    void SourceEditorGeneric::save()
    {
        if (!this->getProjectItem()->hasPath()) {
            throw std::runtime_error("SourceEditorGeneric::save: Cannot save a file without a filename");
        }
		
        this->getProjectItem()->save(this->editorWidget->toPlainText().toStdString());
        
        emit sourceChanged(this);
    }
    
    void SourceEditorGeneric::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->editorWidget->toPlainText().toStdString();
        
        this->getProjectItem()->save(content, filename);
        
        emit sourceChanged(this);
    }
    
    void SourceEditorGeneric::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->getProjectItem()->open(filename);
        
        this->editorWidget->blockSignals(true);
        this->editorWidget->setText(QString::fromStdString(content));
        this->editorWidget->blockSignals(false);
        
        emit sourceChanged(this);
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
    
    const felide::model::ProjectItem* SourceEditorGeneric::getProjectItem() const 
    {
        return this->projectItem;
    }

    felide::model::ProjectItem* SourceEditorGeneric::getProjectItem()
    {
        return this->projectItem;
    }
}}
