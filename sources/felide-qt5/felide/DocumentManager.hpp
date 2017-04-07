
#pragma once

#ifndef __felide_documentmanager_hpp__
#define __felide_documentmanager_hpp__

#include <QWidget>
#include <memory>

namespace felide {
    class DocumentManager : public QWidget {
        Q_OBJECT

    public:
        DocumentManager(QWidget *parent);

        ~DocumentManager();

        void openDocument(const QString &title, const QString &documentPath);

    private:
        struct Private;
        std::unique_ptr<Private> m_impl;
    };
}

#endif
