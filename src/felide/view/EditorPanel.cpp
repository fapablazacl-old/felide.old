
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
        
        // layout
        QGridLayout *layout = nullptr;
        
        layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget, 0, 0);
        
        this->setLayout(layout);
    }
    
    void EditorPanel::openEditor(SourceEditor *editor) 
    {
        this->tabWidget->addTab(editor, editor->getTitle());
        
        QObject::connect(editor, &SourceEditor::sourceChanged, [this](SourceEditor *editor) {
            int index = this->tabWidget->indexOf(editor);
            
            std::cout << "editorChanged(). index: " << index << ". Title: " << editor->getTitle().toStdString() << std::endl;
            
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
