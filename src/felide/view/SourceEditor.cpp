
#include "SourceEditor.hpp"


namespace felide { namespace view {

    using namespace felide::model;
    
    int SourceEditor::documentCount = 0;
    
    SourceEditor::SourceEditor(QWidget *parent) : QWidget(parent)
    {
        this->increaseDocumentCount();
        this->editorNumber = SourceEditor::getDocumentCount();
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
    
    int SourceEditor::getEditorNumber() const
    {
        return this->editorNumber;
    }
    
    bool SourceEditor::isNew() const
    {
        const ProjectItem *projectItem = this->getProjectItem();
        return !projectItem->hasPath() && !projectItem->isModified();
    }
}}
