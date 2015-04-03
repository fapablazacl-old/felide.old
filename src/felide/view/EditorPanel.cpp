
#include "EditorPanel.hpp"

#include <QGridLayout>
#include <iostream>

namespace felide { namespace view {

    EditorPanel::EditorPanel(QWidget *parent) : QWidget(parent)
    {
        // Control
        this->tabWidget = new QTabWidget(this);
        this->tabWidget->setTabsClosable(true);
        
        QObject::connect(this->tabWidget, &QTabWidget::currentChanged, [this](int index) {
            emit this->editorChanged();
        });
        
        QObject::connect(this->tabWidget, &QTabWidget::tabCloseRequested, [this](int index) {
            Editor *editor = static_cast<Editor*>(this->tabWidget->widget(index));
            emit this->editorClosed(editor);
        });
        
        // layout
        QGridLayout *layout = nullptr;
        
        layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget, 0, 0);
        
        this->setLayout(layout);
    }
    
    void EditorPanel::openEditor(Editor *editor) 
    {
        this->tabWidget->addTab(editor, editor->getTitle());
        
        QObject::connect(editor, &Editor::sourceChanged, [this](Editor *editor) {
            int index = this->tabWidget->indexOf(editor);
            this->tabWidget->setTabText(index, editor->getTitle());
        });
    }
    
    void EditorPanel::closeEditor(Editor *editor) 
    {
        int index = this->tabWidget->indexOf(editor);
        this->tabWidget->removeTab(index);
    }
    
    Editor* EditorPanel::getActiveEditor()
    {
        Editor* editor = nullptr;
        
        editor = static_cast<Editor*>(this->tabWidget->currentWidget());
        
        return editor;
    }
    
    const Editor* EditorPanel::getActiveEditor() const
    {
        const Editor* editor = nullptr;
        
        editor = static_cast<const Editor*>(this->tabWidget->currentWidget());
        
        return editor;
    }
    
    Editor* EditorPanel::findNewEditor() const
    {
        Editor *result = nullptr;
        
        for (int i=0; i<this->tabWidget->count(); i++) {
            Editor *editor = nullptr;
            editor = static_cast<Editor*>(this->tabWidget->widget(i));
            
            if (editor->isNew()) {
                result = editor;
            }
        }
        
        return result;
    }
    
    void EditorPanel::activateEditor(Editor *editor)
    {
        this->tabWidget->setCurrentWidget(editor);
    }
}}
