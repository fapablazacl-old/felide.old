
#include "Editor.hpp"


namespace felide { namespace view {

    using namespace felide::model;
    
    int Editor::documentCount = 0;
    
    Editor::Editor(QWidget *parent) : QWidget(parent)
    {
        this->increaseDocumentCount();
        this->editorNumber = Editor::getDocumentCount();
    }
    
    Editor::~Editor() {}
    
    void Editor::increaseDocumentCount()
    {
        Editor::documentCount += 1;
    }

    int Editor::getDocumentCount()
    {
        return Editor::documentCount;
    }
    
    int Editor::getEditorNumber() const
    {
        return this->editorNumber;
    }
    
    bool Editor::isNew() const
    {
        const ProjectItem *projectItem = this->getProjectItem();
        return !projectItem->hasPath() && !projectItem->isModified();
    }
}}
