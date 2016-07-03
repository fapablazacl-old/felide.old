
#include "TabbedEditor.hpp"

#include "EditorImpl.hpp"
#include "MainFrameImpl.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <QGridLayout>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

namespace felide { namespace view { namespace qt5 {

    TabbedEditor::TabbedEditor(QWidget *parent) : QWidget(parent) {
        m_tabWidget = new QTabWidget(this);
        m_tabWidget->setTabsClosable(true);

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(m_tabWidget);
        this->setLayout(layout);

        connect(m_tabWidget, &QTabWidget::tabCloseRequested, [this](int index) {
            auto view = static_cast<EditorImpl*>(m_tabWidget->widget(index));
            auto mainFrame = static_cast<MainFrameImpl*>(this->parent());

            mainFrame->getHandler()->handleFileClose(view);
        });
    }

    EditorImpl* TabbedEditor::openEditor(ProjectItemPtr item) {
		std::string name = item->getName() + " ";

        QString title = QString::fromStdString(name);
        return this->openEditor(std::move(item), title);
    }

    EditorImpl* TabbedEditor::openEditor(ProjectItemPtr item, const QString &title) {
        EditorImpl *view = new EditorImpl(m_tabWidget, std::move(item));

        view->setTabbedEditor(this);

        m_tabWidget->addTab(view, title);
        m_tabWidget->setCurrentWidget(view);
        view->setFocus();
        
        QObject::connect(view, &EditorImpl::titleUpdated, this, &TabbedEditor::editorTitledChanged);

        return view;
    }

    EditorImpl* TabbedEditor::getCurrentEditor() {
        QWidget *widget = m_tabWidget->currentWidget();

        if (!widget) {
            return nullptr;
        }

        return static_cast<EditorImpl*>(widget);
    }

    const EditorImpl* TabbedEditor::getCurrentEditor() const {
        const QWidget *widget = m_tabWidget->currentWidget();

        if (!widget) {
            return nullptr;
        }

        return static_cast<const EditorImpl*>(widget);
    }
    
    void TabbedEditor::closeEditor(const EditorImpl *view) {
        assert(view);

        const int editorIndex = this->getEditorIndex(view);
        m_tabWidget->removeTab(editorIndex);
    }

    int TabbedEditor::getEditorIndex(const EditorImpl* view) const {
        assert(view);

        int index = 0;
        bool found = false;

        for (index=0; index<m_tabWidget->count(); index++) {
            if (m_tabWidget->widget(index) == view) {
                found = true;
                break;
            }
        }

        if (found) {
            return index;
        } else {
            throw std::runtime_error("TabbedEditor::getEditorIndex: editor not found.");
        }
    }

    void TabbedEditor::editorTitledChanged(const EditorImpl* view) {
        assert(view);

        auto mainFrame = static_cast<MainFrameImpl*>(this->parent());

        mainFrame->getHandler()->handleEditorChanged(const_cast<EditorImpl*>(view));
    }

    const int TabbedEditor::getEditorCount() const {
        return m_tabWidget->count();
    }

    Editor* TabbedEditor::getEditor(const int index) {
        return dynamic_cast<Editor*>(m_tabWidget->widget(index));
    }

    const Editor* TabbedEditor::getEditor(const int index) const {
        return dynamic_cast<Editor*>(m_tabWidget->widget(index));
    }

    void TabbedEditor::setEditorTitle(Editor *view, const QString &title) {
        const int index = this->getEditorIndex(static_cast<EditorImpl*>(view));
        m_tabWidget->setTabText(index, title);
    }
}}}
