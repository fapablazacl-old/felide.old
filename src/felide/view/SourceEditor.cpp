
#include "SourceEditor.hpp"


namespace felide { namespace view {

    using namespace felide::model;
    
    int SourceEditor::documentCount = 0;
    
    SourceEditor::SourceEditor(QWidget *parent) : QWidget(parent)
    {
        this->increaseDocumentCount();
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
}}
