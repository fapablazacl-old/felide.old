
#include "SourceEditor.hpp"

namespace felide { namespace view {
    
    SourceEditor::SourceEditor() 
    {
    }
	
    QString SourceEditor::getTitle() const
    {
        return QString();
    }
    
    bool SourceEditor::getDirtyFlag() const
    {
        return true;
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
    
    QString SourceEditor::getFilePath() const
    {
		return "";
    }
    
    bool SourceEditor::hasFilePath() const
    {
        return false;
    }
}}
