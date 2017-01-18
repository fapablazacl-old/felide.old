
#pragma once

#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QWindow>
#include <QTextEdit>

namespace felide { namespace view { namespace qt5 {

    class OutputWindow : public QWidget {
        Q_OBJECT
        
    public:
        explicit OutputWindow(QWidget *parent = nullptr);
        
        void appendLine(const QString &str);

        QString text() const;
        
    private:
        
        QTextEdit *m_textEdit = nullptr;
        
    signals:
        
        
    public slots:
        
        
    };

}}}

#endif
