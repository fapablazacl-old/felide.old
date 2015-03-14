
#include "SourceEditor.hpp"


namespace felide { namespace view {

    using namespace felide::model;
    
    int SourceEditor::documentCount = 1;
    
    SourceEditor::SourceEditor(QWidget *parent) : QWidget(parent)
    {
    }
    
    SourceEditor::~SourceEditor() {}
    
    void SourceEditor::increaseDocumentCount()
    {
        SourceEditor::documentCount += 1;
    }

    int SourceEditor::getDocumentCount()
    {
        return SourceEditor::documentCount;
    }
    
    QString SourceEditor::getTitle() const
    {
        return QString();
    }
    
    void SourceEditor::save()
    {
    }
    
    void SourceEditor::save(const QString &filePath)
    {
    }
    
    void SourceEditor::load(const QString &filePath)
    {
    }
    
    void SourceEditor::undo()
    {
    }
    
    void SourceEditor::redo()
    {
    }
    
    void SourceEditor::copy()
    {
    }
    
    void SourceEditor::cut()
    {
    }
    
    void SourceEditor::paste()
    {
    }
    
    const Source* SourceEditor::getSource() const
    {
        return nullptr;
    }
}}
