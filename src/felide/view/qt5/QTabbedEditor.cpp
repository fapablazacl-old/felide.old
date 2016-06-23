
#include "QTabbedEditor.hpp"
#include "QEditor.hpp"
#include "QMainFrame.hpp"
#include <iostream>
#include <stdexcept>
#include <QGridLayout>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

namespace felide { namespace view { namespace qt5 {

    QTabbedEditor::QTabbedEditor(QWidget *parent) : QWidget(parent) {
        this->tabWidget = new QTabWidget(this);
        this->tabWidget->setTabsClosable(true);

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(this->tabWidget);
        this->setLayout(layout);

        connect(this->tabWidget, &QTabWidget::tabCloseRequested, [this](int index) {
            auto view = static_cast<QEditor*>(this->tabWidget->widget(index));
            auto mainFrame = static_cast<QMainFrame*>(this->parent());

            mainFrame->getHandler()->handleFileClose(view);
        });
    }

    QEditor* QTabbedEditor::openEditor(ProjectItemPtr item) {
		std::string name = item->getName() + " ";

        QString title = QString::fromStdString(name);
        return this->openEditor(std::move(item), title);
    }

    QEditor* QTabbedEditor::openEditor(ProjectItemPtr item, const QString &title) {
        QEditor *view = new QEditor(this->tabWidget, std::move(item));

        view->setTabbedEditor(this);

        this->tabWidget->addTab(view, title);
        this->tabWidget->setCurrentWidget(view);
        view->setFocus();
        
        QObject::connect(view, &QEditor::titleUpdated, this, &QTabbedEditor::editorTitledChanged);

        return view;
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
    
    void QTabbedEditor::closeEditor(const QEditor *view) {
        assert(view);

        const int editorIndex = this->getEditorIndex(view);
        this->tabWidget->removeTab(editorIndex);
    }

    int QTabbedEditor::getEditorIndex(const QEditor* view) const {
        assert(view);

        int index = 0;
        bool found = false;

        for (index=0; index<this->tabWidget->count(); index++) {
            if (this->tabWidget->widget(index) == view) {
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

    void QTabbedEditor::editorTitledChanged(const QEditor* view) {
        assert(view);

        auto mainFrame = static_cast<QMainFrame*>(this->parent());

        mainFrame->getHandler()->handleEditorChanged(const_cast<QEditor*>(view));
    }

    const int QTabbedEditor::getEditorCount() const {
        return this->tabWidget->count();
    }

    Editor* QTabbedEditor::getEditor(const int index) {
        return dynamic_cast<Editor*>(this->tabWidget->widget(index));
    }

    const Editor* QTabbedEditor::getEditor(const int index) const {
        return dynamic_cast<Editor*>(this->tabWidget->widget(index));
    }

    void QTabbedEditor::setEditorTitle(Editor *view, const QString &title) {
        const int index = this->getEditorIndex(static_cast<QEditor*>(view));
        this->tabWidget->setTabText(index, title);
    }
}}}
