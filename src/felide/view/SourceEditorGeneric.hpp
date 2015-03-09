#ifndef __FELIDE_VIEW_SOURCEEDITORGENERIC_HPP__
#define __FELIDE_VIEW_SOURCEEDITORGENERIC_HPP__

#include <QWidget>
#include <memory>

#include <felide/view/SourceEditor.hpp>

namespace felide { namespace view {
    class SourceEditorGeneric : public SourceEditor {
	public:
		Q_OBJECT

	public:
        SourceEditorGeneric();
        explicit SourceEditorGeneric(const QString &filePath);
    
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
		struct Impl;
		std::unique_ptr<Impl> impl;
	};
}}

#endif
