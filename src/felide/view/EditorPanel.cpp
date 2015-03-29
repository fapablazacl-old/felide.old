
#include "EditorPanel.hpp"

#include <QGridLayout>
#include <iostream>

namespace felide { namespace view {

    EditorPanel::EditorPanel(QWidget *parent) : QWidget(parent)
    {
        this->tabWidget = new QTabWidget(this);
        
        QGridLayout *layout = nullptr;
        
        layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget, 0, 0);
        
        this->setLayout(layout);
    }
    
    void EditorPanel::openEditor(SourceEditor *editor) 
    {
        this->tabWidget->addTab(editor, editor->getTitle());
        
        QObject::connect(editor, &SourceEditor::editorChanged, [this](SourceEditor *editor) {
            std::cout << "ON CHANGED!" << std::endl;
            int index = this->tabWidget->indexOf(editor);
            this->tabWidget->setTabText(index, editor->getTitle());
        });
    }
    
    void EditorPanel::closeEditor(SourceEditor *editor) 
    {
    }
    
    SourceEditor* EditorPanel::getActiveEditor()
    {
        SourceEditor* editor = nullptr;
        
        editor = static_cast<SourceEditor*>(this->tabWidget->currentWidget());
        
        return editor;
    }
    
    const SourceEditor* EditorPanel::getActiveEditor() const
    {
        return nullptr;
    }
}}
