#include "OutputWindow.hpp"

#include <QBoxLayout>

namespace felide { namespace view { namespace qt5 {
    OutputWindow::OutputWindow(QWidget *parent) : QWidget(parent) {
        m_textEdit = new QTextEdit(this);
        
        auto layout = new QBoxLayout(QBoxLayout::RightToLeft, this);
        
        layout->addWidget(m_textEdit);
        
        this->setLayout(layout);
    }
    
    void OutputWindow::appendLine(const QString &str) {
        m_textEdit->append(str);
    }
    
    QString OutputWindow::text() const {
        return m_textEdit->toPlainText();
    }
}}}
