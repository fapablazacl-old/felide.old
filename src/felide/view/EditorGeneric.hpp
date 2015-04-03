#ifndef __FELIDE_VIEW_EDITORGENERIC_HPP__
#define __FELIDE_VIEW_EDITORGENERIC_HPP__

#include <QWidget>
#include <QTextEdit>
#include <memory>

#include <felide/view/Editor.hpp>

namespace felide { namespace view {
    class EditorGeneric : public Editor {
	public:
		Q_OBJECT

	public:
        explicit EditorGeneric(QWidget *parent);
        explicit EditorGeneric(QWidget *parent, const QString &filePath);
        
        virtual ~EditorGeneric();
        
        virtual QString getFileTitle() const override;
        
        virtual QString getTitle() const override;
    
        virtual void new_() override;
        virtual void save() override;
        virtual void save(const QString &filePath) override;
        virtual void load(const QString &filePath) override;
        
        virtual void undo() override;
        virtual void redo() override;
        virtual void copy() override;
        virtual void cut() override;
        virtual void paste() override;
        
        virtual const felide::model::ProjectItem* getProjectItem() const override;
        virtual felide::model::ProjectItem* getProjectItem() override;
        
    private:
        void createWidget();
        
	private:
        QTextEdit *editorWidget = nullptr;
        felide::model::ProjectItem *projectItem = nullptr;
	};
}}

#endif
