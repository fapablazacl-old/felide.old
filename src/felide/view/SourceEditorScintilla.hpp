
#if 0

#ifndef __FELIDE_VIEW_SOURCEEDITORSCINTILLA_HPP__
#define __FELIDE_VIEW_SOURCEEDITORSCINTILLA_HPP__

#include <QWidget>
#include <memory>

#include <felide/model/Source.hpp>
#include <felide/view/SourceEditor.hpp>

namespace felide { namespace view {
    
    class SourceEditorScintilla : public SourceEditor {
	public:
        Q_OBJECT
        
    public:
        SourceEditorScintilla();
        explicit SourceEditorScintilla(const QString &filePath);
    
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
		void initializeEditor();

	private:
		// struct Impl;
		// std::unique_ptr<Impl> impl;
    };
}}

#endif  // __FELIDE_VIEW_SOURCEEDITORSCINTILLA_HPP__

#endif
