
#include "TabbedEditor.hpp"
#include "Editor.hpp"
#include <iostream>
#include <QGridLayout>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

namespace felide { namespace qt5 {
    
    TabbedEditor::TabbedEditor(QWidget *parent) : QWidget(parent) {
        this->tabWidget = new QTabWidget(this);
        this->tabWidget->setTabsClosable(true);
        
        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget);
        this->setLayout(layout);
    }
    
    void TabbedEditor::openEditor(ProjectItem *item) {
        QString title = QString::fromStdString(item->getName());
        this->openEditor(item, title);
    }
    
    void TabbedEditor::openEditor(ProjectItem *item, const QString &title) {
        QWidget *editor = new Editor(this->tabWidget, item);
        this->tabWidget->addTab(editor, title);
        this->tabWidget->setCurrentWidget(editor);
        
        connect(static_cast<Editor*>(editor), &Editor::titleUpdated, this, &TabbedEditor::editorTitledChanged);
    }
    
    Editor* TabbedEditor::getCurrentEditor() {
        QWidget *widget = this->tabWidget->currentWidget();
        
        if (!widget) {
            return nullptr;
        }
        
        return static_cast<Editor*>(widget);
    }

    const Editor* TabbedEditor::getCurrentEditor() const {
        const QWidget *widget = this->tabWidget->currentWidget();
        
        if (!widget) {
            return nullptr;
        }
        
        return static_cast<const Editor*>(widget);
    }
    
    void TabbedEditor::closeEditor() {
        int editorIndex = this->tabWidget->currentIndex();
        this->tabWidget->removeTab(editorIndex);
    }
    
    int TabbedEditor::getEditorIndex(const Editor* editor) const {
        int index = 0;
        bool found = false;
        
        auto children = this->tabWidget->children();
        
        for (index=0; index<children.size(); index++) {
            if (children.at(index) == editor) {
                found = true;
                break;
            }
        }
        
        if (found) {
            return index;
        } else {
            // TODO: Throw exception?
            return -1;            
        }
    }
    
    void TabbedEditor::editorTitledChanged(const Editor* editor) {
        std::cout << "TabbedEditor::editorTitledChanged" << std::endl;
        
        if (editor->getItem()->hasPath()) {
            const int index = this->getEditorIndex(editor);
            const QString title = QString::fromStdString(editor->getItem()->getName());
            
            this->tabWidget->setTabText(index, title);
        } else {
            // TODO: Implement tab title update for non-on-disk tabs
        }
    }
}}
