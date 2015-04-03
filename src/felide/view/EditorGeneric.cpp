
#include "EditorGeneric.hpp"

#include <sstream>
#include <memory>
#include <boost/filesystem.hpp>

#include <QTextEdit>
#include <QGridLayout>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    using namespace felide::model;

    namespace fs = boost::filesystem;
    
    void EditorGeneric::createWidget()
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
    
    EditorGeneric::EditorGeneric(QWidget *parent) : Editor(parent)
    {
        this->createWidget();
    }
    
    EditorGeneric::EditorGeneric(QWidget *parent, const QString &filePath) : Editor(parent)
    {
        this->createWidget();
        this->load(filePath);
    }
    
    EditorGeneric::~EditorGeneric()
    {
        boost::checked_delete(this->projectItem);
    }
    
    QString EditorGeneric::getFileTitle() const
    {
        std::string fileTitle;
        
        if (this->getProjectItem()->hasPath()) {
            fileTitle = this->getProjectItem()->getName();
        } else {
            fileTitle = "Untitled " + std::to_string(this->getEditorNumber());
        }
        
        return QString::fromStdString(fileTitle);
    }
    
    QString EditorGeneric::getTitle() const
    {
        std::stringstream ss;
        
        ss << (this->getProjectItem()->isModified()?"[*] ":"");
        ss << this->getFileTitle().toStdString() << " ";
        
        return QString::fromStdString(ss.str());
    }
    
    void EditorGeneric::new_() 
    {
        this->editorWidget->setText("");
        this->getProjectItem()->new_();   
    }
    
    void EditorGeneric::save()
    {
        if (!this->getProjectItem()->hasPath()) {
            throw std::runtime_error("EditorGeneric::save: Cannot save a file without a filename");
        }
		
        this->getProjectItem()->save(this->editorWidget->toPlainText().toStdString());
        
        emit sourceChanged(this);
    }
    
    void EditorGeneric::save(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->editorWidget->toPlainText().toStdString();
        
        this->getProjectItem()->save(content, filename);
        
        emit sourceChanged(this);
    }
    
    void EditorGeneric::load(const QString &filePath)
    {
        std::string filename = filePath.toStdString();
        std::string content = this->getProjectItem()->open(filename);
        
        this->editorWidget->blockSignals(true);
        this->editorWidget->setText(QString::fromStdString(content));
        this->editorWidget->blockSignals(false);
        
        emit sourceChanged(this);
    }
    
    void EditorGeneric::undo()
    {
        this->editorWidget->undo();
    }
    
    void EditorGeneric::redo()
    {
        this->editorWidget->redo();
    }
    
    void EditorGeneric::copy()
    {
        this->editorWidget->copy();
    }
    
    void EditorGeneric::cut()
    {
        this->editorWidget->cut();
    }
    
    void EditorGeneric::paste()
    {
        this->editorWidget->paste();
    }
    
    const felide::model::ProjectItem* EditorGeneric::getProjectItem() const 
    {
        return this->projectItem;
    }

    felide::model::ProjectItem* EditorGeneric::getProjectItem()
    {
        return this->projectItem;
    }
}}
