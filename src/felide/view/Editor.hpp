
#ifndef __FELIDE_VIEW_SOURCEEDITOR_HPP__
#define __FELIDE_VIEW_SOURCEEDITOR_HPP__

#include <QWidget>
#include <felide/model/ProjectItem.hpp>

namespace felide { namespace view {
    
    class Editor : public QWidget {
	public:
        Q_OBJECT
        
    public:
        Editor(QWidget *parent);
        virtual ~Editor() = 0;
        
        virtual QString getFileTitle() const = 0;
        
        virtual QString getTitle() const = 0;
        
        virtual void new_() = 0;
        virtual void save() = 0;
        virtual void save(const QString &filePath) = 0;
        virtual void load(const QString &filePath) = 0;
        
        virtual void undo() = 0;
        virtual void redo() = 0;
        virtual void copy() = 0;
        virtual void cut() = 0;
        virtual void paste() = 0;
        
        virtual const felide::model::ProjectItem* getProjectItem() const = 0;
        virtual felide::model::ProjectItem* getProjectItem() = 0;
        
        bool isNew() const;
        
    private:
        int editorNumber = 0;
    
    protected:
        int getEditorNumber() const;
        
    signals:
        void sourceChanged(Editor *editor);
        
    protected:
        static void increaseDocumentCount();
        static int getDocumentCount();
        
    private:
        static int documentCount;
    };
}}

#endif  // __FELIDE_VIEW_SOURCEEDITOR_HPP__
