
#ifndef __FELIDE_VIEW_SOURCEEDITOR_HPP__
#define __FELIDE_VIEW_SOURCEEDITOR_HPP__

#include <QWidget>
#include <Qsci/qsciscintilla.h>
#include <memory>

#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    class SourceEditor : public QWidget 
    {
        Q_OBJECT
        
    public:
        SourceEditor();
        explicit SourceEditor(const QString &filePath);
    
        QString getTitle() const;
        bool getDirtyFlag() const;
        
        void save();
        void save(const QString &filePath);
        void load(const QString &filePath);
        
        void undo();
        void redo();
        void copy();
        void cut();
        void paste();
    
        QString getFilePath() const;
    
        bool hasFilePath() const;
    
    private:
        void setLexer(QsciLexer *lexer);
    
    private:
        QsciScintilla *editorWidget = nullptr;
        felide::model::Source source;
    };
}}

#endif  // __FELIDE_VIEW_SOURCEEDITOR_HPP__
