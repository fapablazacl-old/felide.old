
#ifndef __FELIDE_VIEW_SOURCEEDITOR_HPP__
#define __FELIDE_VIEW_SOURCEEDITOR_HPP__

#include <QWidget>
#include <felide/model/Source.hpp>

namespace felide { namespace view {
    
    class SourceEditor : public QWidget {
	public:
        Q_OBJECT
        
    public:
        virtual ~SourceEditor() = 0;
        explicit SourceEditor(QWidget *parent);
        
        virtual QString getTitle() const;
        
        virtual void save();
        virtual void save(const QString &filePath);
        virtual void load(const QString &filePath);
        
        virtual void undo();
        virtual void redo();
        virtual void copy();
        virtual void cut();
        virtual void paste();
        
        virtual const felide::model::Source* getSource() const;

    signals:
        void editorChanged(const QString &editorTitle);
        
    public:
        static void increaseDocumentCount();
        static int getDocumentCount();
        
    private:
        static int documentCount;
    };
}}

#endif  // __FELIDE_VIEW_SOURCEEDITOR_HPP__
