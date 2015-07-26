
#include "TabbedEditor.hpp"
#include "Editor.hpp"
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
        this->openEditor(item, "");
    }
    
    void TabbedEditor::openEditor(ProjectItem *item, const QString &title) {
        QWidget *editor = new Editor(this->tabWidget, item);
        this->tabWidget->addTab(editor, title);
    }
}}
