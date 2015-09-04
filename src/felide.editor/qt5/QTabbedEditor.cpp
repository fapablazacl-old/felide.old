
#include "QTabbedEditor.hpp"
#include "QEditor.hpp"
#include <iostream>
#include <stdexcept>
#include <QGridLayout>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

namespace felide { namespace qt5 {

    QTabbedEditor::QTabbedEditor(QWidget *parent) : QWidget(parent) {
        this->tabWidget = new QTabWidget(this);
        this->tabWidget->setTabsClosable(true);

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget);
        this->setLayout(layout);

        connect(this->tabWidget, &QTabWidget::tabCloseRequested, [this](int index) {
            /*
            if (index < 0 || index >= this->tabWidget->count()) {
                return;
            }
            */

            const QEditor* editor = static_cast<const QEditor*>(this->tabWidget->widget(index));
            this->closeEditor(editor);
        });
    }

    void QTabbedEditor::openEditor(ProjectItem *item) {
        QString title = QString::fromStdString(item->getName());
        this->openEditor(item, title);
    }

    void QTabbedEditor::openEditor(ProjectItem *item, const QString &title) {
        QEditor *editor = new QEditor(this->tabWidget, item);

        this->tabWidget->addTab(editor, title);
        this->tabWidget->setCurrentWidget(editor);


        connect(editor, &QEditor::titleUpdated, this, &QTabbedEditor::editorTitledChanged);
    }

    QEditor* QTabbedEditor::getCurrentEditor() {
        QWidget *widget = this->tabWidget->currentWidget();

        if (!widget) {
            return nullptr;
        }

        return static_cast<QEditor*>(widget);
    }

    const QEditor* QTabbedEditor::getCurrentEditor() const {
        const QWidget *widget = this->tabWidget->currentWidget();

        if (!widget) {
            return nullptr;
        }

        return static_cast<const QEditor*>(widget);
    }

    void QTabbedEditor::closeEditor(const QEditor *editor) {
        const int editorIndex = this->getEditorIndex(editor);
        this->tabWidget->removeTab(editorIndex);
    }

    int QTabbedEditor::getEditorIndex(const QEditor* editor) const {
        if (!editor) {
            throw std::runtime_error("TabbedEditor::getEditorIndex: Editor not found.");
        }

        int index = 0;
        bool found = false;

        for (index=0; index<this->tabWidget->count(); index++) {
            if (this->tabWidget->widget(index) == editor) {
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

    void QTabbedEditor::editorTitledChanged(const QEditor* editor) {
        if (editor->getItem()->hasPath()) {
            const int index = this->getEditorIndex(editor);

            const bool modified = editor->getItem()->isModified();
            const QString title = QString::fromStdString(editor->getItem()->getName());

            this->tabWidget->setTabText(index, title + (modified?"[*]":""));
        } else {
            // TODO: Implement tab title update for non-on-disk tabs
        }
    }
}}
