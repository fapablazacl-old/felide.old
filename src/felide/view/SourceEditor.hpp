
#ifndef __FELIDE_VIEW_SOURCEEDITOR_HPP__
#define __FELIDE_VIEW_SOURCEEDITOR_HPP__

#include <QWidget>

namespace felide { namespace view {
    
    class SourceEditor : public QWidget {
	public:
        Q_OBJECT
        
    public:
        SourceEditor();
		
        virtual QString getTitle() const;
        virtual bool getDirtyFlag() const;
        
        virtual void save();
        virtual void save(const QString &filePath);
        virtual void load(const QString &filePath);
        
        virtual void undo();
        virtual void redo();
        virtual void copy();
        virtual void cut();
        virtual void paste();
    
        virtual QString getFilePath() const;
    
        virtual bool hasFilePath() const;
    };
}}

#endif  // __FELIDE_VIEW_SOURCEEDITOR_HPP__
