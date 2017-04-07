
#include "DocumentManager.hpp"

#include <QTabWidget>
#include <QVBoxLayout>
#include <QTextEdit>

#include <fstream>
#include <cassert>

#include "felide/FileUtil.hpp"

namespace felide {
    struct DocumentManager::Private {
        QTabWidget *tabWidget = nullptr;

        Private(QWidget *parent) {
            tabWidget = new QTabWidget(parent);
            tabWidget->setTabsClosable(true);

            parent->setLayout(new QVBoxLayout());
            parent->layout()->addWidget(tabWidget);
        }
    };

    DocumentManager::DocumentManager(QWidget *parent) 
        : QWidget(parent), m_impl(new DocumentManager::Private(this)) {

        
    }

    DocumentManager::~DocumentManager() {}

    void DocumentManager::openDocument(const QString &title, const QString &documentPath) {
        const auto textEdit = new QTextEdit(m_impl->tabWidget);
        const auto content = FileUtil::loadFile(documentPath.toStdString());

        textEdit->setText(QString::fromStdString(content));

        m_impl->tabWidget->addTab(textEdit, title);
    }
}
