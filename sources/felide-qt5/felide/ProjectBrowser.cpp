
#include "ProjectBrowser.hpp"

#include <iostream>
#include <QVBoxLayout>
#include <QBoxLayout>

namespace felide {
    ProjectBrowser::ProjectBrowser (QWidget *parent) 
        : QWidget(parent) {

        m_treeView = new QTreeView(this);

        this->setLayout(new QVBoxLayout(this));
        this->layout()->addWidget(m_treeView);
    }

    ProjectBrowser::~ProjectBrowser() {}

    void ProjectBrowser::setProjectFolder(const QString &projectFolder) {
        m_projectFolder = projectFolder;

        //
        m_fileSystemModel = new QFileSystemModel(this);
        m_fileSystemModel->setFilter(QDir::NoDotAndDotDot);
        m_fileSystemModel->setRootPath(projectFolder);

        m_treeView->setModel(m_fileSystemModel);

        QModelIndex index = m_fileSystemModel->index(projectFolder);

        m_treeView->setRootIndex(index);
    }

    QString ProjectBrowser::projectFolder() const {
        return m_projectFolder;
    }
}
