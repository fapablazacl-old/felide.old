
#include "DocumentManager.hpp"

#include <QTabWidget>
#include <QVBoxLayout>

namespace felide {
    struct DocumentManager::Private {
        QTabWidget *tabWidget = nullptr;

        Private(QWidget *parent) {
            tabWidget = new QTabWidget(parent);

            parent->setLayout(new QVBoxLayout());
            parent->layout()->addWidget(tabWidget);
        }
    };

    DocumentManager::DocumentManager(QWidget *parent) 
        : QWidget(parent), m_impl(new DocumentManager::Private(this)) {
    }

    DocumentManager::~DocumentManager() {}
}
